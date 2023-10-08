#include <stdio.h>
#define MAXLINE 1000
int mygetline(void);
void copy(void);
int max;
char line[MAXLINE];
char longest[MAXLINE];
int main()
{
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    while ((len = mygetline()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }
    if (max > 0)
    {
        printf("\nThe longest is: %s\n length = %d", longest, max);
    }
    return 0;
}
int mygetline(void)
{
    int c;
    int i;
    extern char line[];
    i = 0;
    while ((i < MAXLINE - 1) && ((c = getchar()) != EOF) && (c != '\n'))
    {
        line[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}