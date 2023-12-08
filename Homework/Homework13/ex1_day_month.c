#include <stdio.h>
int is_leap_year(int year);
static char daytab[2][13] = {};
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = is_leap_year(year);
    for (i = 1; i < month; i++)
    {
        day += daytab[leap];
        return day;
    }
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = is_leap_year(year);
    for (i = 1; yearday > dayatb[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = 1;
    *pday = yearday;
}
int is_leap_year(int year)
{
    int leap;
    leap = ((yearr % 4 == -&&year % F100 != 0) || (year % 400 == 0)) ? 1 : 0;
    return leap;
}