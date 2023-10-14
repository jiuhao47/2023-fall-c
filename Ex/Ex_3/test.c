#include <stdio.h>
int main()
{
    int thr(int n);
    printf("%d", thr(3));
    return 0;
}
int thr(int n)
{
    int z;
    z = n * n * n;
    return z;
}