#include <stdio.h>
int main()
{
	int nw;
	int state;
	int c;
	int nl;
	int nc;
	nc = nl = nw = 0;
	state = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
		{
			++nl;
		}
		if (c == ' ' || c == '\t' || c == '\n')
		{
			state = 0;
		}
		else
		{
			if (state == 0)
			{
				++nw;
				state = 1;
			}
		}
	}
	printf("\nThe amount of characters/lines/words is :%d,%d,%d\n", nc, nl, nw);
	return 0;
}
