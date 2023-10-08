#include <stdio.h>
int main()
{
	int num;
	int h;
	int mod(int m, int n);
	num = 1;
	while (num <= 1000)
	{
		h = 1;
		num = num + 1;
		for (int j = 2; j < num; j++)
		{
			h = h * mod(num, j);
		}
		if (h == 1)
			printf("%6d", num);
	}
	return 0;
}

int mod(int m, int n)
{
	if (m % n == 0)
		return 0;
	else
		return 1;
}
