#include <stdio.h>
#include <stdlib.h>
void output(int n, int k);

int main(int argc, char *argv[])
{
    int para[2];
    while (--argc > 0)
    {
        para[argc - 1] = atoi(argv[argc]);
    }
    output(para[0], para[1]);
    return 0;
}

void output(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            printf("Out:%d!\n", i);
        }
    }
}