#include <stdio.h>
#include <ctype.h>
int main()
{
	int c;
	int state;
	int alpha_1;
	int alpha[26];
	int decide(int);
	for (int i = 1; i <= 26; i++)
	{
		alpha[i] = 0;
	}
	state = 0;
	alpha_1 = -1;
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ') || (c == '\n') || (c == '\t'))
		{
			state = 0;
		}
		else if ((state == 0) && ((c != ' ') && (c != '\n') && (c != '\t')))
		{
			state = 1;
			if ((isalpha(c) != 0))
			{
				c = toupper(c);
				state = 2;
			}
		}
		else if ((state == 2) && ((c != ' ') && (c != '\n') && (c != '\t')))
		{
			if (isalpha(c) != 0)
			{
				c = tolower(c);
			}
		}
		printf("%c", c);
	}
	return 0;
}

int decide(int x)
{
	int c;
	int d;
	c = x - 'a';
	d = x - 'A';
	printf("c=%d", c);
	for (int i = 0; i <= 25; i++)
	{
		if (c == i)
		{
		}
		else
		{
			c = -1;
		}
	}
	return c;
}
