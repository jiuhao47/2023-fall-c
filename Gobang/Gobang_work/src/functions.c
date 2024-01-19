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

void displaychessshape(int *Board, int L, int M)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%11d", Board[i * M + j]);
        }
        printf("\n");
    }
}

int mypow(int x, int n)
{
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp = temp * x;
    }
    return temp;
}

int weight(int x, int y)
{
    return 7 - mymax(myabs(x - 7), myabs(y - 7));
}

int mymax(int x, int y)
{
    return (x > y) ? x : y;
}

int myabs(int x)
{
    return (x >= 0) ? x : ((-1) * x);
}