#include <stdio.h>
int main()
{
    int n = 1;
    int sum;
    int j;
    while (n < 1000)
    {
        j = 1;
        sum = 0;
        while (j < n)
        {
            if (n % j == 0)
            {
                sum = sum + j;
            }
            ++j;
        }
        // printf("%d,%d\n", sum, n);

        if (sum == n)
        {
            printf("%d", n);
            j = 1;
            while (j < n)
            {
                if (n % j == 0)
                {
                    printf(" %d", j);
                }
                ++j;
            }
            printf("\n");
        }
        n++;
    }
    return 0;
}
