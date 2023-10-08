#include <stdio.h>
#define STARTYEAR 2000
#define ENDYEAR 2100
int main()
{
	int year;
	year=STARTYEAR;
	while(year<=2100)
	{
		if((year%4==0)&&(year%100!=0)||(year%400==0))
			printf("%d is leap year\n",year);
		else
			printf("%d is not leap year\n",year);
		year++;
	}
	return 0;
}
