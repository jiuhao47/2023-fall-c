#include <stdio.h>
#define MAXLINE 1000
int mygetline(char s[], int lim);
void copy(char to[], char from[]);
int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("\nThe longest is: %s\n length = %d", longest, max);
    }
    return 0;
}
int mygetline(char s[], int lim)
{
    int c;
    int i;
    i = 0;
    while ((i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'))
    {
        s[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}