#include <stdio.h>
int main()
{
	int nw;
	int state;
	int c;
	int character[26];
	int CHARACTER[26];
	int other;
	other=nw=0;
	for (int i=0;i<26;++i)
	{
		character[i]=0;
		CHARACTER[i]=0;
	}
	state=0;
	while((c=getchar())!=EOF)
	{
		if (c==' '||c=='\t'||c=='\n')
		{
			state=0;
		}
		else
		{
			if (state==0)
			{
				++nw;
				state=1;
				if(c>='A'&&c<='Z')
				{
					++CHARACTER[c-'A'];
				}
				else if(c>='a'&&c<='z')
				{
					++character[c-'a'];
				}
				else
				{
					++other;
				}
			}
		}
	}
	for (int i=0;i<26;++i)
	{
		printf("%c: %d  ",i+'a',character[i]);
		printf("%c: %d\n",i+'A',CHARACTER[i]);
	}
	printf("other: %d\n",other);
	return 0;
	
}
