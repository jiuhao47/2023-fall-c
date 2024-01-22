#include <stdio.h>
#include <string.h>
void reverse(char s[]);
void itoh(int x, char s[]);
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
int main()
{
    int x;
    char s[100];

    scanf("%d", &x);
    itoh(x, s);
    reverse(s);
    printf("%s", s);
    return 0;
}
void itoh(int x, char s[])
{
    int op = x;
    int i = 0;
    char c;
    while (x != 0)
    {
        c = x % 16;
        if (c >= 0 && c <= 9)
        {
            s[i] = c + '0';
        }
        else
        {
            s[i] = c - 10 + 'a';
        }
        ++i;
        x = x / 16;
    }
    s[i] = 'x';
    s[i + 1] = '0';
    s[i + 2] = '\0';
}