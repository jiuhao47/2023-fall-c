#include <stdio.h>
char s[100];
int main()
{
    puts("readytogetplayer\n");
    // flush the buffer
    fflush(stdout);
    gets(s);
    printf("Step(1,2)\n");
    fflush(stdout);
    gets(s);
    printf("Step(2,2)\n");
    fflush(stdout);
    gets(s);
    printf("Step(3,2)\n");
    fflush(stdout);
    gets(s);
    printf("Step(4,2)\n");
    fflush(stdout);
    gets(s);
    printf("Step(5,2)\n");
    fflush(stdout);
    gets(s);
    return 0;
}