#include <stdio.h>
int main()
{
    printf("0x%x\n", 023 << 3 ^ 6 | 0x14);
    printf("0x%x\n", 0x27 & (((~6) + 17) >> 2));
    printf("0x%x\n", 0x8265 & (~0 << 6));
    printf("0x%x", (((~0 << 6))));
    return 0;
}