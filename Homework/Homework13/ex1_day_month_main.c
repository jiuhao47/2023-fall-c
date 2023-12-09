#include <stdio.h>
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main()
{
    int mode;
    int year, month, day;
    int yearday;
    printf("plears choose:\n");
    printf("(1) year-month-day to yearday: press 1\n");
    printf("(2) yearday to year-month-day: press 2\n");
    scanf("%d", &mode);
    if (mode == 1)
    {
        printf("input year:");
        scanf("%d", &year);
        printf("input month:");
        scanf("%d", &month);
        printf("input day:");
        scanf("%d", &day);
        yearday = day_of_year(year, month, day);
        printf("yearday=%d\n", yearday);
    }
    else if (mode == 2)
    {
        printf("input year:");
        scanf("%d", &year);
        printf("input yearday:");
        scanf("%d", &yearday);
        month_day(year, year, &month, &day);
        printf("year=%d month=%d day=%d\n", year, month, day);
    }
    else
    {
        printf("Wrong mode!\n");
    }
    return 0;
}