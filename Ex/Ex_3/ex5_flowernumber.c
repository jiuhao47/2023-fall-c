#include <stdio.h>
int thr(int n);
int main()
{
    int n;
    int answer;
    n = 100;
    while (n < 1000)
    {
        int x, y, z;
        if (n < 10)
        {
            y = z = 0;
            x = n;
        }
        else if ((n >= 10) && (n < 100))
        {
            x = n % 10;
            y = (n - x) / 10;
        }
        else
        {
            x = ((n % 100) % 10);
            y = ((n % 100) - x) / 10;
            z = (n - x - (y * 10)) / 100;
        }

        // printf("%d,%d,%d\n", x, y, z);
        if ((thr(x) + thr(y) + thr(z)) == n)
        {
            printf("%d\n", n);
        }
        n++;
    }
    return 0;
}
int thr(int n)
{
    int z;
    z = n * n * n;
    return z;
}