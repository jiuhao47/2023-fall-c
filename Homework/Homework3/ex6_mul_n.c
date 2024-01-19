#include <stdio.h>
int power(int, int);

int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%3d %6d %6d", i, power(2, i), power(-3, i));
	}
	return 0;
}

int power(int base, int n)
{
	int x, i;
	x = 1;
	for (i = 1; i <= n; ++i)
	{
		x = x * base;
	}
	return x;
}
