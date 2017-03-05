#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/* structure for student details */
struct student_details_linked
{
		char student_name[100];
		int student_number;
		struct student_details_linked *next;
};

struct student_details_binary
{
		char student_name[100];
		int student_number;
		struct student_details_binary *right;
		struct student_details_binary *left;
};


/* declaring functions for linked mode */
void newStudentLinked(struct student_details_linked **root);
void deleteLinked(struct student_details_linked **root);
void deleteAllLinked(struct student_details_linked **root);
void printLinked(struct student_details_linked **root);
void printAllLinked(struct student_details_linked **root);
void saveFileLinked(struct student_details_linked **root);
void readFileLinked(struct student_details_linked **root);

/* declaring functions for binary mode */
void newStudentBinary(struct student_details_binary **root);
void deleteBinary(struct student_details_binary **root);
void deleteAllBinary(struct student_details_binary **root);
void printBinary(struct student_details_binary **root);
void printAllBinary(struct student_details_binary **root);
void saveFileBinary(struct student_details_binary **root);
void readFileBinary(struct student_details_binary **root);


int main(int argc, char *argv[])
{
	int what_do;
	int exit = 0;
    char mode[6];

    /* checks if user inputed a valid argument, and if not
     * then asks user to choose mode */
    if(argc==1 || ((strcmp(argv[1],"linked")!=0) &&
               (strcmp(argv[1],"binary")!=0)))
    {
        printf("No valid argument found.\nPlease select the mode you want:"
               "\n1.Linked\n2.Binary\n");
       scanf("%d",&what_do);

       switch(what_do)
       {
           case 1:
               strcpy(mode,"linked");
               break;
            case 2:
               strcpy(mode,"binary");
               break;
       }
    }
    else
    {
        strcpy(mode,argv[1]);
    }

    /* runs if mode is linked, and goes through while loop with the different options
     * until user quits */
    if(strcmp(mode,"linked")==0)
    {
	    struct student_details_linked *root = NULL;	
	    while(exit == 0)
	    {
            fpurge(stdin); /* purge input in case user tried to input
                              invalid characters, e.g. arrow key up in cmd */
	    	what_do = 0;  /*  reset what_do (again in case user
                              input invalid characters) */
	    	printf("\nType your option:"
            "\n1: Introduce new student\n2: Remove student\n"
            "3: Print student report\n4: Print report for all students\n"
            "5: Save to file\n6: Retrieve data from file\n7: Exit\n");
	    	scanf("%d",&what_do);
	    	
            /* switch for each of the options + 
             * default switch in case invalid characters are inputted */
	    	switch(what_do)
	    	{
	    		case 1:
	    		newStudentLinked(&root);
	    		break;
	    		
	    		case 2:
                deleteLinked(&root);
                printf("%d",root);
	    		break;

	    		case 3:
                printLinked(&root);
	    		break;

	    		case 4:
                printAllLinked(&root);
	    		break;

	    		case 5:
                saveFileLinked(&root);
	    		break;

	    		case 6:
                readFileLinked(&root);
                printf("%d",root);
	    		break;
	    		
	    		case 7:
	    		exit = 1;
	    		break;
	    	
	    		default:
	    		printf("Input not recognised\n\n");
	    		break;	
	    	}
        }
    }
    /* same as above but for binary */
    else if(strcmp(mode, "binary")==0)
    {
	    struct student_details_binary *root = NULL;	
	    while(exit == 0)
	    {
            fpurge(stdin); /* purge input in case user tried to input
                              invalid characters, e.g. arrow key up in cmd */
	    	what_do = 0;  /*  reset what_do (again in case user
                              input invalid characters) */
	    	printf("\nType your option:"
            "\n1: Introduce new student\n2: Remove student\n"
            "3: Print student report\n4: Print report for all students\n"
            "5: Save to file\n6: Retrieve data from file\n7: Exit\n");
	    	scanf("%d",&what_do);
	    	
            /* switch for each of the options + 
             * default switch in case invalid characters are inputted */
            switch(what_do)
            {
                case 1:
                newStudentBinary(&root);
                break;
                
                case 2:
                deleteBinary(&root);
                break;

                case 3:
                printBinary(&root);
                break;

                case 4:
                printAllBinary(&root);
                break;

                case 5:
                saveFileBinary(&root);
                break;

                case 6:
                readFileBinary(&root);
                break;
                
                case 7:
                exit = 1;
                break;
            
                default:
                printf("Input not recognised\n\n");
                break;	
            }
        }
	}
	return 0;
}

/* adds a student to linked list - sorted alphabetically */
void newStudentLinked(struct student_details_linked **root)
{
	int student_number;
	char student_name[100];
	struct student_details_linked *current;
	struct student_details_linked *previous = NULL;
	struct student_details_linked *new;

    /* taking input for new entry from user */
	fpurge(stdin); 
	printf("Please input the new student's name\n");
	scanf("%s",&student_name);
	printf("Please input the new student's number\n");
	scanf("%d",&student_number);

	if(*root == NULL) /* runs if root has no value */ 
	{
	    current = malloc(sizeof(struct student_details_linked));
	    strcpy(current->student_name, student_name);
	    current->student_number = student_number;
	    current->next = NULL;
	    *root = current;
        return;
    } 

	else	
	{
        /* mallocs and assigns new data */
	    new = malloc(sizeof(struct student_details_linked));
	    strcpy(new->student_name, student_name);
	    new->student_number = student_number;
        new->next = NULL;
        
        current = *root;

        /* iterates through list until either: the last element is reached, 
         * or until the strcmp gives a positive value (meaning that the next 
         * element is further down alphabetically  */
        while(current->next != NULL &&
        strcmp(current->student_name,student_name) < 0)
        {
            printf("loop running\n");
            previous = current;
            current = current->next;
        }

        /* prepends entry & re-assigns root */
        if(previous == NULL)         
        {
			new->next = current;
			*root = new;
            return;
        }
        /* checks if entry should be the last in the list, and if so then
         * appends it */
        else if(current->next == NULL &&
        strcmp(current->student_name,student_name) < 0)
        {
	    current->next = new;
        return;
	    }
        /* otherwise inserts entry between elements */
        else
        {
	    previous->next = new;
	    new->next = current;
        return;
	    }
    }
}

/* Iterates through linked list printing values */
void printAllLinked(struct student_details_linked **root)
{
	struct student_details_linked *current;

	current = *root;

	while(current != NULL)
	{
	    printf("Student name is: %s\n", current->student_name);  
	    printf("Student number is: %d\n\n", current->student_number);  
	    current = current->next;
	}
}

/* deletes a user by searching for student name */
void deleteLinked(struct student_details_linked **root)
{
    struct student_details_linked *current;
    struct student_details_linked *previous = NULL;
    char student_name[100];

    /* checks if root is null to stop errors  */
    if(*root == NULL)
    {
        printf("Please input students before trying to remove them!\n");
        return;
    }

	current = *root;

	fpurge(stdin); 
    printf("Please enter the name of the student you would like to remove\n");
    scanf("%s",&student_name);

    /* loops over list, until either the end is reached or a match is found */
	while(current->next != NULL && strcmp(current->student_name,student_name) != 0)
	{
        previous = current;    
	    current = current->next;
	}

    /* if match is found then following code runs */
    if(strcmp(current->student_name,student_name) == 0)
    {
        /* if prev is unchanged, and current-> next is null there is only one element
         * this deletes element and sets root to NULL */
        if(current->next == NULL && previous == NULL)
        {
            free(current);
            *root = NULL;
            printf("Student removed\n\n");
            return;
        }
        /* if prev is unchanged and current->next is not null, then we delete current
         * and reassign root */
        else if(previous == NULL && current->next != NULL)
        {
            previous = current->next;
            free(current);
            *root = previous;
            printf("Student removed\n\n");
            return;
        }  
        /* otherwise we just delete current and reassign prev pointer to next list 
         * element */
        else if(previous != NULL)
        {
            previous->next = current->next;
            free(current);
            printf("Student removed\n\n");
            return;
        }
    }
    /* complains to user if student not found */
    else
    {
        printf("A student with that name was not found\n");
        return;
    }
}

void deleteAllLinked(struct student_details_linked **root)
{
	struct student_details_linked *current;
	struct student_details_linked *previous;

    if(*root == NULL)
    {
        printf("No changes to save!\n");
        return;
    }

	current = *root;
    *root = NULL;
    while(current != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
	} 
}
/* prints a specific user's details by searching by name */
void printLinked(struct student_details_linked **root)
{
    struct student_details_linked *current;
    char student_name[100];

    /* checks if root is null to stop errors  */
    if(*root == NULL)
    {
        printf("Please enter some students first!\n");
        return;
    }

	current = *root;

	fpurge(stdin); 
    printf("Please enter the name of the student you would like to display\n");
    scanf("%s",&student_name);

    /* loops over list, until either the end is reached or a match is found */
	while(current->next != NULL && strcmp(current->student_name,student_name) != 0)
	{
	    current = current->next;
	}

    /* if match is found then following code runs */
    if(strcmp(current->student_name,student_name) == 0)
    {
        printf("\nStudent Name: %s\n",current->student_name);
        printf("Student Number: %d\n\n",current->student_number);
    }
    /* complains to user if student not found */
    else
    {
        printf("A student with that name was not found\n\n");
    }
}

void saveFileLinked(struct student_details_linked **root)
{
    char file_name[50];
	struct student_details_linked *current;

	current = *root;
    
    printf("\nPlease input your file name\n");
    scanf("%s",&file_name);
    
    FILE * file = fopen(file_name, "wb"); 

	while(current != NULL)
	{
        fwrite(current, sizeof(struct student_details_linked), 1, file);
	    current = current->next;
	}
     fclose(file);
}

void readFileLinked(struct student_details_linked **root)
{
    int what_do=0;
    char file_name[50];
	struct student_details_linked *current;
	struct student_details_linked *previous = NULL;

	current = *root;

    printf("\nYour current changes will be lost. "
            "Would you like to save?\n"
            "1.Yes\n2.No\n");
    scanf("%d",&what_do);

    switch(what_do)
    {
        case 1:
            saveFileLinked(&*root);
            deleteAllLinked(&*root);
        break;
        case 2:
            deleteAllLinked(&*root);
        break;
    }

    
    printf("\nPlease input the file you want to read.\n");
    scanf("%s",&file_name);

    FILE * file = fopen(file_name, "rb"); 

    if (file == NULL)
    {
        printf("No file found");
        fclose(file);
        return;
    }
    else if (file != NULL)
    {
        current = malloc(sizeof(struct student_details_linked));
        fread(current, sizeof(struct student_details_linked), 1, file);
        previous = current;
        current->next = previous;

    }

    fclose(file);
    *root = current;
}

void newStudentBinary(struct student_details_binary **root)
{
}

void printAllBinary(struct student_details_binary **root)
{
}

void deleteBinary(struct student_details_binary **root)
{
}

void printBinary(struct student_details_binary **root)
{
}

void saveFileBinary(struct student_details_binary **root)
{
}

void readFileBinary(struct student_details_binary **root)
{
}
