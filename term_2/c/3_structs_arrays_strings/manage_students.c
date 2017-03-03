#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
	int i,c,number;
	int what_do, num_students=0;
	int exit = 0;
	int student_number, new_number_of_courses;
	
	struct student_details
	{
		char student_name[50];
		int student_number;
		int number_of_courses;
		int student_marks[30];
	};
	
	struct student_details database[100];
	
	while(exit == 0)
	{
		fpurge(stdin);
		what_do = 0;
		printf("Type your option:\n1: Introduce new student\n2: Introduce Mark\n3: Print report of all students\n4: Exit\n");
		scanf("%d",&what_do);
		
		switch(what_do)
		{
			case 1:
			fpurge(stdin);
			printf("Please input the student's name\n");
			scanf("%[^\n]",&database[num_students].student_name);
			
			printf("Please input the student number\n");
			scanf("%d",&database[num_students].student_number);
			
			printf("Please input the number of courses the student is enrolled in\n");
			scanf("%d",&database[num_students].number_of_courses);
			
			for(i=0;i<database[num_students].number_of_courses;i++)
			{
				printf("please input the marks for course number %d\n",i+1);
				scanf("%d",&database[num_students].student_marks[i]);
			}
								
			num_students++;
			break;
					
			case 2:
			
			
			for(i=0;i<num_students;i++)
			{
				printf("\n");
				printf("%d -> student name: %s\n",(i+1),database[i].student_name);
			}
			printf("\n");
			
			printf("please choose your student: \n");
			scanf("%d",&number);
			number = number - 1;
			
			printf("Please input the number of courses\n");
			scanf("%d",&new_number_of_courses);
				
			for(i=0; i<new_number_of_courses; i++)
			{
				printf("please input the marks for course number %d\n", (i + 1 + database[number].number_of_courses));
				scanf("%d",&database[number].student_marks[(i + database[number].number_of_courses)]);
			}
			
			database[number].number_of_courses = database[number].number_of_courses + new_number_of_courses;
			break;
			
			case 3:
			for(i=0;i<num_students;i++)
			{
				printf("\n");
				printf("student name: %s\n",database[i].student_name);
				printf("student number: %d\n",database[i].student_number);
				printf("student marks: ");
				for(c=0;c<database[i].number_of_courses;c++)
				{
					printf("%d ",database[i].student_marks[c]);
				}
				printf("\n");
			}
			printf("\n");
			break;
			
			case 4:
			exit = 1;
			break;
		
			default:
			printf("Input not recognised\n\n");
			break;	
		}
	}
	return 0;
}