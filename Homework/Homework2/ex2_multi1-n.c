#include <stdio.h>
int main()
{
	int product;
	int n;
	int i;
	printf("Enter a number:\n");
	scanf("%d",&n);
	i=1;
	product=1;
	do
	{
		product=product*i;
		i++;
	}while(i<=n);
	printf("1*2*...*%d=%d\n",n,product);
	return 0;
	
}
