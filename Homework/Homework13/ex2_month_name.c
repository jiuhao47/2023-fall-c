#include <stdio.h>
char *month_name(int n);
int main()
{
    int n;
    char *pname;
    printf("Input number:");
    scanf("%d", &n);
    pname = month_name(n);
    printf("%s\n", pname);
    return 0;
}
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}