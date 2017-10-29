#include <stdio.h>
#include <stdlib.h>

float average(float n1, float n2, float n3);
int factorial(int n1);
int squareroot(int n1);
float heron_root(float n1);


int main(void)
{
	int whatDo;
	int integer1;
	int exit;
	int outputInt;
	float float1, float2, float3;
	float outputFloat;
	
	exit = 1;
	
	while(exit == 1)
	{
		fpurge(stdin);
		whatDo = 0;
		printf("Type your option:\n1: Average\n2: Factorial\n3: Square root\n4: Exit\n");
		scanf("%d",&whatDo);
		switch(whatDo)
		{
			case 1:
			printf("Input 3 float numbers\n");
			printf("please input your first float\n");
			scanf("%f",&float1);
			printf("please input your second float\n");
			scanf("%f",&float2);
			printf("please input your third float\n");
			scanf("%f",&float3);
			outputFloat = average(float1,float2,float3);
			printf("The average is %f\n\n", outputFloat);
			break;
					
			case 2:
			printf("Input an integer\n");
			scanf("%d", &integer1);
			outputInt = factorial(integer1);
			printf("The factorial of %d, is %d\n\n", integer1,outputInt);
			break;
			
			case 3:
			printf("Input an integer\n");
			scanf("%d", &integer1);
			outputInt = squareroot(integer1);
			printf("The squareroot of %d is %d\n\n", integer1, outputInt);
			break;
			
			case 4:
			exit = 0;
			break;
		
			default:
			printf("Input not recognised\n\n");
			break;	
		}
	}
	return 0;
}

float average(float n1, float n2, float n3)
{
	float avg;
	
	avg = (n1 + n2 + n3)/3;
	
	return avg;
}

int factorial(int n1)
{
	int factorialX, x;
	
	factorialX = n1;
	for (x=n1-1; x>0;x--)
	{
		factorialX = factorialX * x;
	}
	return factorialX;
}

int squareroot(int n1)
{
	int x;
	for (x=0;x<= n1/2;x++)
	{
		if (x*x == n1)
		{
			return x;
		}
	}
	return -1;
}

float heron_root(float n1)
{	
	float guess, lastguess;
	
	if (n1<=0)
	{
		return -1;
	}
	else
	{
		guess = n1/3;
		while(1)
		{
			lastguess = guess;
			guess = (guess + n1/guess)/2.0;
			if (abs(lastguess - guess) <= 0.0001)
			{
			break;
			}
		}
		return guess;
	}
}