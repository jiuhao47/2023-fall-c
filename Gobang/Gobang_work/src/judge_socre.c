#include "head.h"

int judge_score(int x, int y, int layer)
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