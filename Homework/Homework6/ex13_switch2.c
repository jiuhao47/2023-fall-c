#include <stdio.h>
int main()
{
    int a, num = 0;
    scanf("%d", &a);
    switch (a)
    {
    case 0:
        num = num + 0;
        break;
    case 1:
        num = num + 1;
        break;
    case 2:
        num = num + 2;
        break;
    case 3:
        num = num + 3;
        break;
    case 4:
        num = num + 4;
        break;
    case 5:
        num = num + 5;
        break;
    case 6:
        num = num + 6;
        break;
    }
    printf("num=%d\n", num);
    return 0;
}