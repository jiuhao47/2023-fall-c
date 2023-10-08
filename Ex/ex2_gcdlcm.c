#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int i = 1;
	while (1)
	{
		if (a * i % b == 0)
		{
			break;
		}
		i++;
	}
	printf("lcm=%d\n", a * i);
	printf("gcd=%d\n", (a * b) / (a * i));
	return 0;
}
