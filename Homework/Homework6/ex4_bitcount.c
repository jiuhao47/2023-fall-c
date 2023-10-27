#include <stdio.h>
unsigned bitcount(unsigned);
int main()
{
    int a = 0x56674, b;
    b = bitcount(a);
    printf("b=%d\n", b);
    return 0;
}
unsigned bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            ++b;
    return b;
}