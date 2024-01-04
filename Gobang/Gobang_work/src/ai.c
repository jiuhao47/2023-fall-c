#include "head.h"

int scoreBoard[SIZE][SIZE];
int evolveLayers;
int ai(void)
{
    pos.x = rand() % SIZE + 1;
    pos.y = rand() % SIZE;
    ai_input(pos.x, pos.y);
    return 0;
}

void ai_input(int x, int y)
{
    gamestates.playerstate = !gamestates.playerstate;
    arrayForInnerBoardLayout[SIZE - x][y] = (!gamestates.playerstate == BLACK) ? BLACKCHESSCURRENT : WHITECHESSCURRENT;
}

void socre(void)
{
    evolveLayers = 0;
    if (evolveLayers < MAXEVOLVELAYERS)
    {
        evolveLayers = evolveLayers + 1;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (arrayForInnerBoardLayout[i][j] == EMPTY)
                {
                    arrayForInnerBoardLayout[i][j] = (gamestates.playerstate == BLACK) ? BLACKCHESS : WHITECHESS;
                    arrayForInnerBoardLayout[i][j] = EMPTY;
                }
            }
        }
    }
}