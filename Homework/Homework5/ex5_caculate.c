#include <stdio.h>
int main()
{
    int a, b;
    a = 5, b = 2;
    printf("a=%d,b=%d,a/b=%d,a%%b=%d%d\n", a, b, a / b, a % b);
    a = -5, b = -2;
    printf("a=%d,b=%d,a/b=%d,a%%b=%d%d\n", a, b, a / b, a % b);
    return 0;
}