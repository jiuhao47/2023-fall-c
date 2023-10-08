#include <stdio.h>
void mygetline(char s[]);
void clearchar(char s[], int lim);
void check_n(char s[], int lim, int n);
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
    clearchar(line, lim);
    mygetline(line);
    // printf("%s", line);
    // printf("%s", line);
    check_n(line, lim, n);
    return 0;
}
void mygetline(char s[])
{
    int c;
    int i;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}

void clearchar(char s[], int lim)
{
    for (int j = 0; j < lim; j++)
    {
        s[j] = '\0';
    }
}
void check_n(char s[], int lim, int n)
{
    char mid[lim];
    clearchar(mid, lim);
    int k, m;
    k = 0;
    m = 0;
    while ((k < lim) && (s[k] != '\0'))
    {
        mid[m] = s[k];
        // printf("string:%s,m=%d,n=%d,k=%d,\n", mid, m, n, k);
        if ((mid[m] == '\n'))
        {
            if (m > n)
            {
                printf("Output: %s", mid);
                clearchar(mid, lim);
            }
            m = 0;
        }
        else
        {
            ++m;
        }
        ++k;
    }
}
