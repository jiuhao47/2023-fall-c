#include "head.h"

// int check_507745524;
//   mode 1,2,3,4
//   1:x
//   2:y
//   3:x-y
//   4:y-x

void chessShapeToken(int x, int y, int *Board, int *chessshape)
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
                chessshape[mode * 9 + i + 4] = Board[displayPosToInnerPos(temppoint.x, temppoint.y)];
            }
            else
            {
                chessshape[mode * 9 + i + 4] = 5;
            }
        }
    }
}

void gamejudger(void)
{
    int check;
    check = judge(pos.x, pos.y);
    // printf("(%c,%d):score:%d\n", 'A' + pos.y, pos.x, judge_score(pos.x, pos.y, arrayForInnerBoardLayout[0]));
    winHandle(check);
}

int judge(int x, int y)
{
    int chessshape[DIRECTION][9];
    chessShapeToken(x, y, arrayForInnerBoardLayout[0], chessshape[0]);
    int count = chainjudge(chessshape[0]);
    if (count == -1)
    {
        return 1;
    }
    else if (count == -2)
    {
        return 2;
    }
    else
    {
        if (doublefourjudge(x, y, chessshape[0]))
        {
            return 4;
        }
        else
        {
            if (doublethreejudge(x, y, chessshape[0]))
            {
                return 3;
            }
        }
    }
    return 0;
}

// 复杂禁手的问题，也就是空点是否可以落子是个需要实现的问题。
// 详情见与lzh的聊天
/*
int checkempty(int x, int y, int mode, int i)
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
    struct point temppoint;
    temppoint.x = x + (i - 4) * dx;
    temppoint.y = y + (i - 4) * dy;
    arrayForInnerBoardLayout[SIZE - temppoint.x][temppoint.y] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
    int tempcheck;
    tempcheck = judge(temppoint.x, temppoint.y);
    arrayForInnerBoardLayout[SIZE - temppoint.x][temppoint.y] = EMPTY;
    return tempcheck;
}
*/
int chainjudge(int *chessshape)
{
    int count = 0;
    int maxcount = 0;
    for (int mode = 0; mode < DIRECTION; mode++)
    {
        count = 0;
        for (int i = 0; i < 9; i++)
        {
            if ((chessshape[mode * 9 + i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS)) || (chessshape[mode * 9 + i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT)))
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
        else if ((maxcount > 5))
        {
            return -2;
        }
    }
    return maxcount;
}

int chainjudge_mode(int mode, int *chessshape)
{
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS)) || (chessshape[mode * 9 + i] == ((!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT)))
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
    else if ((maxcount > 5))
    {
        return -2;
    }

    return maxcount;
}

int doublefourjudge(int x, int y, int *chessshape)
{
    int count = 0;

    for (int mode = 0; mode < DIRECTION; mode++)
    {
        if ((chainjudge_mode(mode, chessshape) < 4) && (fourjudge(x, y, mode, chessshape) == 2))
        {
            return 1;
        }
        count = count + ((fourjudge(x, y, mode, chessshape) > 0) ? 1 : 0);
        if (count >= 2)
        {
            return 1;
        }
    }
    return 0;
}

int fourjudge(int x, int y, int mode, int *chessshape)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == EMPTY))
        {
            chessshape[mode * 9 + i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            if (chainjudge(chessshape) == -1)
            {
                count = count + 1;
            }
            chessshape[mode * 9 + i] = EMPTY;
        }
    }
    return count;
}

int doublethreejudge(int x, int y, int *chessshape)
{
    int count = 0;
    for (int mode = 0; mode < DIRECTION; mode++)
    {
        count = count + ((threejudge(x, y, mode, chessshape) > 0) ? 1 : 0);
        if (count >= 2)
        {
            return 1;
        }
    }
    return 0;
}

int threejudge(int x, int y, int mode, int *chessshape)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == EMPTY))
        {
            chessshape[mode * 9 + i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            if (fourjudge(x, y, mode, chessshape) == 2)
            {
                // if (checkempty(x, y, mode, i) <= 1)
                //{
                //  printf("Enter\n");
                count = count + 1;
                // printf("addCount=%d\n", count);
                //}
            }
            chessshape[mode * 9 + i] = EMPTY;
        }
    }
    return (count > 0) ? 1 : 0;
}
