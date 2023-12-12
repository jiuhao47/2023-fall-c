#include "head.h"

struct player black, white;

void initplayer(void)
{
    black.chess = BLACKCHESS;
    black.chesscurrent = BLACKCHESSCURRENT;
    white.chess = WHITECHESS;
    white.chesscurrent = WHITECHESSCURRENT;
}

// did not use