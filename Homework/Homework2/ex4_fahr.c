#include <stdio.h>
#define LOWER 0.0
#define UPPER 300
#define STEP 20
int main()
{
	float fahr,celcius;
	fahr=celcius=LOWER;
	while(fahr<=UPPER)
	{
		celcius=(fahr-32.0)*5.0/9.0;
		printf("fahr:%6.1f\tcelcius%6.1f\n",fahr,celcius);
		fahr=fahr+STEP;
	}
	return 0;
}
