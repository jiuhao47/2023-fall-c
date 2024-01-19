#include <stdio.h>
int main()
{
	int nl, c;
	nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
			++nl;
	}
	printf("\n the amount of line :%d\n", nl);
	return 0;
}
