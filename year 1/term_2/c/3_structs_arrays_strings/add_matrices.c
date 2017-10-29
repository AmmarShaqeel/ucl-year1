#include<stdio.h>
#include<string.h>


void AddMatrix(int matrix_one[20][20], int matrix_two[20][20], int destination_matrix[20][20], int num_rows, int num_columns);

void PrintMatrix(int matrix[20][20], int num_columns, int num_rows);

int main()
{
	int i, c; //variables for count
	int matrix_one[20][20], matrix_two[20][20], destination_matrix[20][20], num_rows, num_columns; //info variables
	
	printf("INPUT ROWS PLEASE\n");
	scanf("%d",&num_rows);
	
	printf("INPUT COLUMNS PLEASE\n");
	scanf("%d",&num_columns);
	
	printf("Inputing data for matrix_one \n");
	
	for(i=0; i<num_columns; i++)
	{
		for(c=0; c<num_rows; c++)
		{
			printf("value for %dx%d\n",i+1,c+1);
			scanf("%d",&matrix_one[c][i]);
		}
	}
	
	PrintMatrix(matrix_one,num_columns,num_rows);
	
	printf("Inputing data for matrix_two \n");
	
	for(i=0; i<num_columns; i++)
	{
		for(c=0; c<num_rows; c++)
		{
			printf("value for %dx%d\n",i+1,c+1);
			scanf("%d",&matrix_two[c][i]);
		}
	}
	
	PrintMatrix(matrix_two, num_columns, num_rows);
	
	AddMatrix(matrix_one,matrix_two,destination_matrix,num_rows,num_columns);
	
	PrintMatrix(destination_matrix, num_rows,num_columns);
	
	return 0;
}

void AddMatrix(int matrix_one[20][20], int matrix_two[20][20], int destination_matrix[20][20], int num_rows, int num_columns)
{
	int i,c;
	
	for(i=0; i<num_columns; i++)
	{
		for(c=0; c<num_rows; c++)
		{
			destination_matrix[i][c] = matrix_one[i][c] + matrix_two[i][c];
		}
	}
}

void PrintMatrix(int matrix[20][20], int num_rows, int num_columns)
{
	int i, c;
	for(i=0; i<num_columns; i++)
	{
		printf("\n[ ");
		for(c=0; c<num_rows; c++)
		{
			printf("%d ",matrix[i][c]);
		}
		printf("]");
	}
	printf("\n");
}