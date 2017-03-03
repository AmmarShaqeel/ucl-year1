#include <stdio.h>
#include <stdlib.h>

float average(float n1, float n2, float n3);
int factorial(int n1);
int squareroot(int n1);


int main(void)
{
	int whatDo;
	int integer1;
	int exit;
	int outputInt;
	float float1, float2, float3;
	float outputFloat;
	
	exit = 1; //setting exit flag for while loop
	
	while(exit == 1) //loop will run forever unless flag is set to 0
	{
		fpurge(stdin); //purges stdin in case of invalid characters
		whatDo = 0;    //resets whatDo
		printf("Type your option:\n1: Average\n2: Factorial\n3: Square root\n4: Exit\n");
		scanf("%d",&whatDo);  //user sets whatDo
		
		//switch lets user pick calculator's function
		switch(whatDo)  
		{
			case 1: //asks for three floats then passes them to average function
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
					
			case 2:  //asks for an integer and passes it to the factorial function
			printf("Input an integer\n");
			scanf("%d", &integer1);
			outputInt = factorial(integer1);
			printf("The factorial of %d, is %d\n\n", integer1,outputInt);
			break;
			
			case 3: //asks for an integer and passes it to the squareroot function
			printf("Input an integer\n");
			scanf("%d", &integer1);
			outputInt = squareroot(integer1);
			printf("The squareroot of %d is %d\n\n", integer1, outputInt);
			break;
			
			case 4: //sets exit flag to zero, cause while loop to end
			exit = 0;
			break;
		
			default: //in event user inputs invalid characters
			printf("Input not recognised\n\n");
			break;	
		}
	}
	return 0;
}


//function takes three floats, adds them, finds average then returns average
float average(float n1, float n2, float n3)
{
	float avg;
	
	avg = (n1 + n2 + n3)/3;
	
	return avg;
}


//function finds factorial of integer
int factorial(int n1) 
{
	int factorialX, x;
	
	factorialX = n1;
	
	//loops from x=input integer to x=0
	//factorial value is stored in factorialX and is updated for each iteration of x
	for (x=n1-1; x>0;x--)
	{
		factorialX = factorialX * x;
	}
	return factorialX;
}


//finds squareroot of a number
int squareroot(int n1)
{
	int x;
	
	//loops from zero to half of number (as the largest integer squareroot is 2)
	for (x=0;x<= n1/2;x++)
	{
		//checks if this iteration of x is the squareroot, if so then breaks and returns the value of x
		if (x*x == n1)
		{
			return x;
		}
	}
	//if integer squareroot of x is not found then the function returns -1 
	return -1;
}