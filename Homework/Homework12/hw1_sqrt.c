#include <stdio.h>
double value(double n);
double sqrt_n(double x1, double x2, double a);
int main()
{
    double a;
    scanf("%lf", &a);
    double x1, x2;
    x1 = a;
    x2 = a + 10;
    printf("%lf", sqrt_n(x1, x2, a));
}

double sqrt_n(double x1, double x2, double a)
{
    while (value(x1 - x2) >= 0.00001)
    {
        double temp;
        temp = x2;
        x2 = 0.5 * (x1 + (a / x1));
        x1 = temp;
        sqrt_n(x1, x2, a);
    }
    if (value(x1 - x2) < 0.00001)
    {
        return x2;
    }
}
double value(double n)
{
    return (n < 0) ? -n : n;
}