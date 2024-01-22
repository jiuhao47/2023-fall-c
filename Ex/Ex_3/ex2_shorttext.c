#include <stdio.h>
#define MAX 999
int mygetline(char s[]);
void copy(char to[], char from[]);
int main()
{
    char string_1[MAX];
    char string_2[MAX];
    char string_3[MAX];
    int len_1, len_2, len_3;
    char c;
    len_2 = MAX;
    len_3 = MAX;
    while ((c = getchar()) != EOF)
    {
        string_1[0] = c;
        len_1 = mygetline(string_1);
        if (((len_1 < len_2) && (len_2 >= len_3)))
        {
            copy(string_2, string_1);
            len_2 = len_1;
            // printf("string_2=%s", string_2);
        }
        else if (((len_1 < len_3) && (len_3 >= len_2)))
        {
            copy(string_3, string_1);
            len_3 = len_1;
            // printf("string_3=%s", string_3);
        }
    }
    printf("%s%s", string_2, string_3);

    return 0;
}
int mygetline(char s[])
{
    int c;
    int i;
    i = 1;
    while ((i < MAX - 1) && ((c = getchar()) != '\n'))
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