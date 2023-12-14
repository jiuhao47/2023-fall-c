#include "head.h"

struct player black, white;

void initplayer(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            black.arrayForInnerMind[i][j] = EMPTY;
            white.arrayForInnerMind[i][j] = EMPTY;
        }
    }
}

void arrayTransform(int player)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (player == BLACK)
            {
                black.arrayForInnerMind[i][j] = (arrayForInnerBoardLayout[i][j] == BLACKCHESS || arrayForInnerBoardLayout[i][j] == BLACKCHESSCURRENT) ? OCCUPIED : EMPTY;
            }
            else
            {
                white.arrayForInnerMind[i][j] = (arrayForInnerBoardLayout[i][j] == WHITECHESS || arrayForInnerBoardLayout[i][j] == WHITECHESSCURRENT) ? OCCUPIED : EMPTY;
            }
        }
    }
}