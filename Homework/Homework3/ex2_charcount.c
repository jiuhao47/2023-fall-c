#include <stdio.h>
int main()
{
	long nc;
	int c;
	nc = 0;
	c = getchar();
	while (c != EOF)
	{
		++nc;
		c = getchar();
	}
	printf("\nthe total number : %ld\n", nc);
	return 0;
}
