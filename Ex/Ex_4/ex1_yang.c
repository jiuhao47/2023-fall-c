#include <stdio.h>
int times(int n);
int comb(int up, int down);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", comb(i, j));
        }
        printf("\n");
    }
    return 0;
}

int comb(int up, int down)
{
    return ((times(up)) / (times(down) * times(up - down)));
}
int times(int n)
{
    int i = 1;
    int sum = 1;
    while (i <= n)
    {
        sum = sum * i;
        ++i;
    }
    return sum;
}