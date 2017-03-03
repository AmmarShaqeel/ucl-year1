#include<stdio.h>

int main(void)
{
	int size, x, max;
	
	printf("please input the number of integers you want to compare\n");
	scanf ("%d",&size);
	
	int numbers[size];
	
	for (x=0; x<size;x++)
	{
		printf("please input the %dth number \n",x+1);
		scanf("%d",&numbers[x]);
		if (numbers[x]>max)
		{
			max = numbers[x];
		}
	}
	
	printf("biggest number is: %d", max);
	return 0;
}