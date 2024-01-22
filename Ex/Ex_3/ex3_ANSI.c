#include <stdio.h>
#define MAX 32
int mygetline(char s[]);
int isLega1ANSI(char s[]);
int main()
{
    char string[MAX];
    int answer;
    answer = mygetline(string);
    if (answer == 1)
    {
        printf("%d", 0);
        // printf("len>\n");
    }
    else
    {
        if (isLega1ANSI(string) == 0)
        {
            printf("%d", 0);
            // printf("false\n");
        }
        else
        {
            printf("%d", 1);
            // printf("right\n");
        }
    }
    return 0;
}
int isLega1ANSI(char s[])
{
    int z;
    if ((((s[0] >= 'A') && (s[0] <= 'Z')) || ((s[0] >= 'a') && (s[0] <= 'z'))) || (s[0] == '_'))
    {
        int i;
        i = 1;
        while ((i < MAX - 1) && (s[i] != '\0'))
        {
            if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z')) || (s[i] == '_') || ((s[i] >= '0') && (s[i] <= '9')))
            {
                z = 1;
            }
            else
            {
                z = 0;
                // printf("mid,%c", s[i]);
                break;
            }
            i++;
        }
    }
    else
    {
        z = 0;
        // printf("title");
    }
    return z;
}
int mygetline(char s[])
{
    int c;
    int i;
    i = 0;
    int result = -1;
    while ((c = getchar()) != '\n')
    {
        if (i > MAX - 1)
        {
            result = 1;
            break;
        }
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (result != 1)
    {
        return 0;
    }

    return result;
}