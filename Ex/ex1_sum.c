#include <stdio.h>
int main()
{
	float sum;
	int n;
	int i;
	float mul(int);
	printf("Enter a number:");
	scanf("%d", &n);
	sum = 1;
	i = 1;
	while (i <= n)
	{
		sum = sum + (1.0 / mul(i));
		i++;
	}
	printf("%f\n", sum);
	return 0;
}
float mul(int x)
{
	int out;
	int i;
	i = 1;
	out = 1;
	while (i <= x)
	{
		out = out * i;
		i = i + 1;
	}
	return out;
}
