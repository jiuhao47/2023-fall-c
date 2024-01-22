#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 100
char pattern[100];
int mygetline(char s[], int lim);
int strindex(char s[], char t[]);
int main()
{
    char line[MAXLINE];
    mygetline(line, MAXLINE);
    mygetline(pattern, MAXLINE);
    pattern[strlen(pattern) - 1] = '\0';
    // printf("%s%s", line, pattern);
    if (strindex(line, pattern) >= 0)
    {
        printf("%d", strindex(line, pattern));
    }
    else
    {
        printf("%d", -1);
    }

    return 0;
}

int mygetline(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
}

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        j = i;
        k = 0;
        while (t[k] != '\0')
        {
            if (s[j] == t[k])
            {
                j++;
                k++;
            }
            else if (t[k] == '@' && isalpha(s[j]))
            {
                j++;
                k++;
            }
            else if (t[k] == '*' && isdigit(s[j]))
            {
                j++;
                k++;
            }
            else
            {
                break;
            }
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}