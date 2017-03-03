#include<stdio.h>

int main(void)
	{
	int n1;
	int n2;
	int n3;
	int biggest;
	
	printf("please input your first integer value \n");
	scanf ("%d",&n1);
	printf("please input your second integer value \n");
	scanf ("%d",&n2);
	printf("please input your third integer value \n");
	scanf ("%d",&n3);
	
	biggest = n1;
	
	if (n2>biggest)
	{
		biggest = n2;
	}
	if (n3>biggest)
	{
		biggest = n3;
	}
	
	printf("Out of the integers: %d, %d, %d, %d is the bigest", n1,n2,n3, biggest);
	return 0;
	}