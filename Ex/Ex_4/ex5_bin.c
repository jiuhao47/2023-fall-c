#include <stdio.h>
#include <string.h>
void reverse(char s[]);
void itob(int x, char s[]);
int atoibin(char s[]);
int atoibin1(char s[]);
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
    int x, y, p, len;
    char ax[100];
    char ay[100];
    char mid1[100];
    char mid2[100];
    scanf("%d %d %d %d", &x, &y, &p, &len);
    itob(x, ax);
    reverse(ax);
    itob(y, ay);
    reverse(ay);
    // printf("%s\n", ax);
    int i = 0;
    while (i < len)
    {
        ax[strlen(ax) - p + i - 1] = ay[strlen(ay) - len + i];
        ++i;
    }
    // printf("%s\n", ax);
    printf("%d", atoibin(ax) - 0x7fffffff);

    return 0;
}
void itob(int x, char s[])
{
    int op;
    if (x >= 0)
    {
        op = x;
    }
    else
    {
        op = x + 0x7fffffff + 1;
    }

    int i = 0;
    char c;
    // printf("op=%d\n", op);
    while (op != 0)
    {
        c = op % 2;
        // printf("%d,c=%c\n", c, c + '0');
        s[i] = c + '0';
        ++i;
        op = op / 2;
        // printf("%d\n", op);
        // printf("%s\n", s);
    }
    s[i] = '\0';
}

int atoibin(char s[])
{
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {

        if (s[i] <= '1' && s[i] >= '0')
        {
            sum = sum * 2 + (s[i] - '0');
        }
        i++;
    }
    return sum;
}

int atoibin1(char s[])
{
    int i = 0;
    int sum = 0;
    int sign = 1;
    while (s[i] != '\0')
    {
        if (s[0] == '1')
        {
            sign = -1;
        }
        else if (s[0] == '0')
        {
            sign = 1;
        }
        if (s[i] <= '1' && s[i] >= '0' && sign == 1)
        {
            sum = sum * 2 + ((s[i] - '0'));
        }
        if (s[i] <= '1' && s[i] >= '0' && sign == 1)
        {
            sum = sum * 2 + ((s[i] - '0'));
        }
        i++;
    }
    return (sum);
}