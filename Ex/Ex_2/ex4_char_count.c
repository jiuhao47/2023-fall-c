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
				int d;
				d = c - 'A';
				alpha[d] = alpha[d] + 1;
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
	for (int i = 0; i <= 25; i++)
	{
		printf("%c: %d\n", i + 65, alpha[i]);
	}
	return 0;
}
