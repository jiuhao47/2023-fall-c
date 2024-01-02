#include "head.h"

//  mode 1,2,3,4
//  1:x
//  2:y
//  3:x-y
//  4:y-x
int chessshape[DIRECTION][9];
void chessShapeToken(int x, int y, int *Board)
{

    for (int mode = 0; mode < DIRECTION; mode++)
    {
        int dx = 0;
        int dy = 0;
        switch (mode)
        {
        case 0:
            dx = 1, dy = 0; // 竖直
            break;
        case 1:
            dx = 0, dy = 1; // 水平
            break;
        case 2:
            dx = 1, dy = 1; //
            break;
        case 3:
            dx = 1, dy = -1;
            break;
        default:;
        }
        for (int i = -4; i <= 4; i++)
        {
            struct point temppoint;
            temppoint.x = x + i * dx;
            temppoint.y = y + i * dy;
            if (pointInBoard(temppoint.x, temppoint.y))
            {
                chessshape[mode][i + 4] = Board[displayPosToInnerPos(temppoint.x, temppoint.y)];
            }
            else
            {
                chessshape[mode][i + 4] = 5;
            }
        }
    }
}

void judge(void)
{
    chessShapeToken(pos.x, pos.y, arrayForInnerBoardLayout[0]);
    statedisplay();
    int count = chainjudge();
    if (count == -1)
    {
        gamestates.runningstate = -2;
    }
    else if (count == -2)
    {
        printf("Longchain!\n");
        gamestates.playerstate = !gamestates.playerstate;
        gamestates.runningstate = -2;
    }
    else
    {
        if (doublefourjudge())
        {
            printf("Double Four!\n");
            gamestates.playerstate = !gamestates.playerstate;
            gamestates.runningstate = -2;
        }
        else
        {
            if (doublethreejudge())
            {
                printf("Double three!\n");
                gamestates.playerstate = !gamestates.playerstate;
                gamestates.runningstate = -2;
            }
        }
    }
}

// 复杂禁手的问题，也就是空点是否可以落子是个需要实现的问题。
// 详情见与lzh的聊天

int chainjudge(void)
{
    int count = 0;
    int maxcount = 0;
    for (int mode = 0; mode < DIRECTION; mode++)
    {
        count = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((chessshape[mode][i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS)) || (chessshape[mode][i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT)))
            {
                count = count + 1;
                maxcount = (maxcount < count) ? count : maxcount;
            }
            else
            {
                count = 0;
            }
        }
        if (maxcount == 5)
        {
            return -1;
        }
        else if ((maxcount > 5) && (!gamestates.playerstate == BLACK))
        {
            return -2;
        }
    }
    return maxcount;
}

int chainjudge_mode(int mode)
{
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode][i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS)) || (chessshape[mode][i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT)))
        {
            count = count + 1;
            maxcount = (maxcount < count) ? count : maxcount;
        }
        else
        {

            count = 0;
        }
    }
    if (maxcount == 5)
    {
        return -1;
    }
    else if ((maxcount > 5) && (!gamestates.playerstate == BLACK))
    {
        return -2;
    }

    return maxcount;
}

int doublefourjudge(void)
{
    int count = 0;

    for (int mode = 0; mode < DIRECTION; mode++)
    {
        if ((chainjudge_mode(mode) < 4) && (fourjudge(mode) == 2))
        {
            return 1;
        }
        count = count + ((fourjudge(mode) > 0) ? 1 : 0);
        if (count >= 2)
        {
            return 1;
        }
    }
    return 0;
}

int fourjudge(int mode)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (chessshape[mode][i] == EMPTY)
        {
            chessshape[mode][i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);

            if (chainjudge() == -1)
            {
                count = count + 1;
            }
            chessshape[mode][i] = EMPTY;
        }
    }
    return count;
}

int doublethreejudge(void)
{
    int count = 0;
    for (int mode = 0; mode < DIRECTION; mode++)
    {
        count = count + ((threejudge(mode) > 0) ? 1 : 0);
        if (count >= 2)
        {
            return 1;
        }
    }
    return 0;
}

int threejudge(int mode)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (chessshape[mode][i] == EMPTY)
        {
            chessshape[mode][i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            // printf("_____________________\n");
            // displaychessshape(chessshape[0], DIRECTION, 9);
            // printf("_____________________\n");
            if (fourjudge(mode) == 2)
            {
                // printf("Enter\n");
                count = count + 1;
                // printf("addCount=%d\n", count);
            }
            chessshape[mode][i] = EMPTY;
        }
    }
    // printf("count=%d\n", count);
    return (count > 0) ? 1 : 0;
}

void displaychessshape(int *Board, int L, int M)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%3d", Board[i * M + j]);
        }
        printf("\n");
    }
}

void statedisplay(void)
{
    displaychessshape(chessshape[0], DIRECTION, 9);
    printf("\n");
    displaychessshape(arrayForInnerBoardLayout[0], SIZE, SIZE);
}
