#include "head.h"

int mygetline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    return i;
}

int pointInBoard(int tempx, int tempy)
{
    int ret = 0;
    if ((tempx > 0) && (tempy >= 0) && (tempx <= SIZE) && (tempy < SIZE))
    {
        ret = 1;
    }
    return ret;
}

int displayPosToInnerPos(int tempx, int tempy)
{
    return (SIZE - (tempx)) * SIZE + tempy;
}
