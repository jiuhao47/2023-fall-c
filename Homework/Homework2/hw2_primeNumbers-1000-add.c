#include <stdio.h>
int main()
{
	float num;
	float i;
	int h;
	int mod(int m, int n);
	num = 1;
	i = 0.0;
	while (num <= 1000)
	{
		h = 1;
		num = num + 1;
		for (int j = 2; j < num; j++)
		{
			h = h * mod(num, j);
		}
		if (h == 1)
			i = i + (1 / num);
	}
	printf("%f\n", i);
	return 0;
}

int mod(int m, int n)
{
	if (m % n == 0)
		return 0;
	else
		return 1;
}
