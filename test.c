#include <stdio.h>
void fun(int n)
{
    if (n < 0)
    {
        printf("-");
        n *= -1;
    }
    while (n % 10 == 0)
    {
        n = n / 10;
    }
    while (n != 0)
    {
        printf("%d", n % 10);
        n = n / 10;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    fun(n);
    return 0;
}