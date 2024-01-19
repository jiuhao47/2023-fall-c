#include "head.h"
int chessshape_score[DIRECTION][9];

//
int judge_score(int x, int y, int *Board)
{
    int count;

    chessShapeToken(x, y, Board, chessshape_score[0]);
    if (!gamestates.playerstate == BLACK)
    {
        count = chainjudge(chessshape_score[0]);
        if (count == -1)
        {
            // printf("Judge:FIVE IN ROW\n");
            return P_FIVEINROW;
        }
        else if (count == -2)
        {
            // printf("Judge:FORBIDDEN\n");
            return FORBIDDEN;
        }
        else
        {
            if (doublefourjudge(x, y, chessshape_score[0]))
            {
                // printf("Judge:FORBIDDEN\n");
                return FORBIDDEN;
            }
            else
            {
                if (doublethreejudge(x, y, chessshape_score[0]))
                {
                    // printf("Judge:FORBIDDEN\n");
                    return FORBIDDEN;
                }
            }
        }
    }
    int fourshape;
    int threeshape;
    int twoshape;
    int pointTotal = 0;
    for (int mode = 0; mode < DIRECTION; mode++)
    {
        if (chainjudge_mode(mode, chessshape_score[0]) < 0)
        {
            
            pointTotal = pointTotal + P_FIVEINROW;
            continue;
        }
        else
        {

            fourshape = fourjudge_score(x, y, mode, chessshape_score[0]);
            if (fourshape == 2)
            {
                // printf("Judge:P_FLEXFOUR\n");
                pointTotal = pointTotal + P_FLEXFOUR;
                continue;
            }
            else if (fourshape == 1)
            {
                // printf("Judge:P_DIRECTFOUR\n");
                pointTotal = pointTotal + P_DIRECTFOUR;
                continue;
            }
            else
            {
                threeshape = threejudge_score(x, y, mode, chessshape_score[0]);
                if (threeshape == 2)
                {
                    // printf("Judge:P_FLEXTHREE\n");
                    pointTotal = pointTotal + P_FLEXTHREE;
                    continue;
                }
                else if (threeshape == 1)
                {
                    // printf("Judge:P_DIRECTTHREE\n");
                    pointTotal = pointTotal + P_DIRECTTHREE;
                    continue;
                }
                else
                {
                    twoshape = twojudge_score(x, y, mode, chessshape_score[0]);
                    if (twoshape == 2)
                    {
                        // printf("Judge:P_FLEXTWO\n");
                        pointTotal = pointTotal + P_FLEXTWO;
                        continue;
                    }
                    else if (twoshape == 1)
                    {
                        // printf("Judge:P_DIRECTTWO\n");
                        pointTotal = pointTotal + P_DIRECTTWO;
                        continue;
                    }
                    else
                    {
                        // printf("Judge:P_ONE\n");
                        pointTotal = pointTotal + P_ONE;
                        continue;
                    }
                }
            }
        }
    }
    return pointTotal;
}
int fourjudge_score(int x, int y, int mode, int *chessshape)
{
    int count = 0;
    int fiveshape = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == EMPTY))
        {
            chessshape[mode * 9 + i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            if (chainjudge_mode(mode, chessshape) == -1)
            {
                count = count + 1;
            }
            chessshape[mode * 9 + i] = EMPTY;
        }
    }
    return count;
    // 2:有两个点可以成5，活四
    // 1:有一个点可以成5，冲四
    // 0:没有点可以成5，
}

int threejudge_score(int x, int y, int mode, int *chessshape)
{
    int count = 0;
    int fourshape = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == EMPTY))
        {
            chessshape[mode * 9 + i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            fourshape = fourjudge_score(x, y, mode, chessshape);
            if (fourshape == 2)
            {
                count = count | 0b10;
                // 可以成活四
            }
            else if (fourshape == 1)
            {
                count = count | 0b01;
                // 可以成冲四
            }
            chessshape[mode * 9 + i] = EMPTY;
        }
    }
    if (count & 0b10)
    {
        count = 2;
    }
    else if (count & 0b1)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }
    return count;
    // 2:活三
    // 1:冲三
    // 0:不能成活四也不能成冲四
}

int twojudge_score(int x, int y, int mode, int *chessshape)
{
    int count = 0;
    int threeshape = 0;
    for (int i = 0; i < 9; i++)
    {
        if ((chessshape[mode * 9 + i] == EMPTY))
        {
            chessshape[mode * 9 + i] = ((!gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS);
            threeshape = threejudge_score(x, y, mode, chessshape);
            if (threeshape == 2)
            {
                count = count | 0b10;
                // 可以成活三
            }
            else if (threeshape == 1)
            {
                count = count | 0b01;
                // 可以成冲三
            }
            chessshape[mode * 9 + i] = EMPTY;
        }
    }
    if (count & 0b10)
    {
        count = 2;
    }
    else if (count & 0b1)
    {
        count = 1;
    }
    else
    {
        count = 0;
    }
    return count;
    // 2:活二
    // 1:冲二
    // 0:不能成活二也不能成冲二
}