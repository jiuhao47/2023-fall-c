#include <stdio.h>
#define MAXLEN 15
int n;
int i = 0;
char s[MAXLEN];
void itoa(int n, char s[]);
int main()
{
    printf("Enter a number\n");
    scanf("%d", &n);
    itoa(n, s);
    s[i] = '\0';
    for (int j = 0; j < MAXLEN; j++)
    {
        printf("%c", s[j]);
    }
    printf("\n%s", s);
    return 0;
}

void itoa(int n, char s[])
{

    if (n < 0)
    {
        s[i] = '-';
        n = -n;
        ++i;
    }
    if (n / 10)
    {
        itoa(n / 10, s);
    }
    s[i] = n % 10 + '0';
    ++i;
}