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
		i=i+2;
	}while(i<=n);
	printf("1*3*...*%d=%d\n",n,product);
	return 0;
	
}
