#include <stdio.h>
#include <ctype.h>
#define MAX 100
int mygetline(char s[]);
double atof(char s[]);
int main()
{
    double x;
    char s[100];
    mygetline(s);
    x = atof(s);
    printf("%.6le", x);
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + s[i] - '0';
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + s[i] - '0';
        power *= 10.0;
    }
    int sum;
    if (s[i] == 'e' || s[i] == 'E')
    {
        // printf("enter e\n");
        ++i;
    }
    int sign2 = 1;
    if (s[i] == '+')
    {
        sign2 = 1;
        // printf("positive");
        i++;
    }
    else if (s[i] == '-')
    {
        sign2 = -1;
        // printf("negative");
        i++;
    }
    if (s[i] == '0')
    {
        ++i;
        // printf("skip");
    }
    for (sum = 0; isdigit(s[i]); i++)
    {
        sum = sum * 10 + s[i] - '0';
    }
    int power2 = 1;
    for (int j = 0; j < sum; j++)
    {
        power2 = power2 * 10;
    }

    // printf("%d,%f,%d,%f,%d,%d\n", sign, val, power2, power, sum, sign2);
    return (sign2 == 1) ? (sign * val * (power2 + 0.0) / power) : (sign * val / (power * (power2 + 0.0)));
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