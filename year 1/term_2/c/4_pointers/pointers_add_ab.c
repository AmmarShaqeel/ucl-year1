#include<stdio.h>

void sumof(int a,int b, int *c)
{
	*c = a+b;
}
int main(void)
{
	int a=10, b=50, c=0;
	sumof(a,b,&c);
	printf("%d\n",c);
}