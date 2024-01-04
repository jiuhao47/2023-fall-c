#include "head.h"

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