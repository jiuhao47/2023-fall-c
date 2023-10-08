#include <stdio.h>
int mygetline(char s[], int lim);
int main()
{
    int n;
    int len;
    int lim;
    printf("Enter a String lenth limitation:");
    scanf("%d", &lim);
    char line[lim];
    printf("Enter a number:");
    scanf("%d", &n);
    while (len = mygetline(line, lim) > 0)
    {
        printf("%d", len);
        if (len > n)
        {
            printf("%s", line);
        }
    }

    return 0;
}
int mygetline(char s[], int lim)
{
    int i, c;
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