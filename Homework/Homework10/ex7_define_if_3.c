#include <stdio.h>
int main()
{
    int a = 10;
    int b = 3;
#if HDR == 1
    a += b;
#endif
    a *= b;
    printf("result=%d\n", a);
    return 0;
}
