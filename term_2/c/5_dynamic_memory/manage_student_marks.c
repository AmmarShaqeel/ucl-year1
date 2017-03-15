#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>

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
void newStudentLinked(struct student_details_linked **root, char student_name[100], int student_number);
void deleteLinked(struct student_details_linked **root, char student_name[100]);
void deleteAllLinked(struct student_details_linked **root);
void printLinked(struct student_details_linked **root, char student_name[100]);
void printAllLinked(struct student_details_linked **root);
void saveLinked(struct student_details_linked **root, FILE **file);
void readLinked(struct student_details_linked **root, FILE **file);

/* declaring functions for binary mode */
void newStudentBinary(struct student_details_binary **root, char student_name[100], int student_number);
int deleteBinary(struct student_details_binary **root, struct student_details_binary **current, struct student_details_binary **previous, char student_name[100], int found);
void deleteAllBinary(struct student_details_binary **root);
void rightRotateBinary(struct student_details_binary **root);
void leftRotateBinary(struct student_details_binary **root);
void balanceBinary(struct student_details_binary **root);
int printBinary(struct student_details_binary **current, char student_name[100], int found);
void printAllBinary(struct student_details_binary **root);
void saveBinary(struct student_details_binary **current, FILE **file);
void readBinary(struct student_details_binary **root, FILE **file);


int main(int argc, char *argv[])
{
	int what_do, student_number;
    char mode[6], student_name[100], file_name[50];
	int exit = 0, found = 0;
    FILE *file;

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

    /* runs if mode is linked, and goes through while loop with the different
     * options
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
	    	printf("\nLINKED MODE\nType your option:"
            "\n1: Introduce new student\n2: Remove student\n"
            "3: Print student report\n4: Print report for all students\n"
            "5: Save to file\n6: Retrieve data from file\n7: Exit\n");
	    	scanf("%d",&what_do);
	    	
            /* switch for each of the options + 
             * default switch in case invalid characters are inputted */
	    	switch(what_do)
	    	{
	    		case 1:
                    printf("Please input the new student's name\n");
                    scanf("%s",&student_name);
                    printf("Please input the new student's number\n");
                    scanf("%d",&student_number);
                    newStudentLinked(&root,student_name, student_number);
	    		break;
	    		
	    		case 2:
                    printf("Please input the student you would like to delete.\n");
                    scanf("%s",&student_name);
                    deleteLinked(&root, student_name);
                    printf("TK: %d\n",root);
	    		break;

	    		case 3:
                    if(root == NULL)
                    {
                        printf("Please enter some students first!\n");
                        break;
                    }

                    printf("Please input the student you would like to print\n");
                    scanf("%s",&student_name);
                    printLinked(&root, student_name);
	    		break;

	    		case 4:
                    printAllLinked(&root);
	    		break;

	    		case 5:
                    printf("\nPlease input your file name\n");
                    scanf("%s",&file_name);
                    file = fopen(file_name, "wb"); 

                    saveLinked(&root, &file);

                    fclose(file);
	    		break;

	    		case 6:
                    printf("TK: %d\n", root);
                    printf("\nPlease input the file you want to read.\n");
                    scanf("%s",&file_name);
                    file = fopen(file_name, "rb"); 

                    readLinked(&root, &file);
                    
                    fclose(file);
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
	    	printf("\nBINARY MODE\nType your option:"
            "\n1: Introduce new student\n2: Remove student\n"
            "3: Print student report\n4: Print report for all students\n"
            "5: Save to file\n6: Retrieve data from file\n7: Exit\n");
	    	scanf("%d",&what_do);
	    	
            /* switch for each of the options + 
             * default switch in case invalid characters are inputted */
            switch(what_do)
            {
                case 1:
                    printf("Please input the new student's name\n");
                    scanf("%s",&student_name);
                    printf("Please input the new student's number\n");
                    scanf("%d",&student_number);

                    newStudentBinary(&root, student_name, student_number);
                break;
                
                case 2:
                    found = 0;

                    if(root == NULL)
                    {
                        printf("Please enter some students first!\n");
                        break;
                    }

                    fpurge(stdin); 
                    printf("Please enter the name of the student you would like to delete\n");
                    scanf("%s",&student_name);

                    found = deleteBinary(&root, &root, NULL, student_name, found); 

                    printf("TK: new root outside %s \n", root->student_name);
                    if(found == 0)
                    {
                        printf("\nNo matching students found\n");
                    }
                break;

                case 3:
                    found = 0;

                    if(root == NULL)
                    {
                        printf("Please enter some students first!\n");
                        break;
                    }

                    fpurge(stdin); 
                    printf("Please enter the name of the student you would like to display\n");
                    scanf("%s",&student_name);

                    found = printBinary(&root, student_name, found); 

                    if(found == 0)
                    {
                        printf("\nNo students found\n");
                    }
                break;

                case 4:
                    printAllBinary(&root);
                break;

                case 5:
                    printf("\nPlease input your file name\n");
                    scanf("%s",&file_name);
                    file = fopen(file_name, "wb"); 

                    saveBinary(&root, &file);

                    fclose(file);
                break;

                case 6:
                    printf("TK: %d\n", root);
                    printf("\nPlease input the file you want to read.\n");
                    scanf("%s",&file_name);
                    file = fopen(file_name, "rb"); 

                    readBinary(&root, &file);

                    fclose(file);
                    balanceBinary(&root);
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
void newStudentLinked(struct student_details_linked **root, char student_name[100], int student_number)
{
	struct student_details_linked *current;
	struct student_details_linked *previous = NULL;
	struct student_details_linked *new;

    current = *root;

    /* taking input for new entry from user */
	new = malloc(sizeof(struct student_details_linked));
	strcpy(new->student_name, student_name);
	new->student_number = student_number;
    new->next = NULL;

	if(*root == NULL) /* runs if root has no value */ 
	{
	    *root = new;
        return;
    } 

	else	
	{
        /* iterates through list until either: the last element is reached, 
         * or until the strcmp gives a positive value (meaning that the next 
         * element is further down alphabetically  */
        while(current->next != NULL &&
        strcmp(current->student_name,new->student_name) < 0)
        {
            previous = current;
            current = current->next;
        }

        /* prepends entry & re-assigns root */
        if(previous == NULL && strcmp(current->student_name,new->student_name)
                > 0)         
        {
			new->next = current;
			*root = new;
            return;
        }
        /* checks if entry should be the last in the list, and if so then
         * appends it */
        else if(current->next == NULL &&
        strcmp(current->student_name,new->student_name) < 0)
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

/* deletes a user by searching for student name */
void deleteLinked(struct student_details_linked **root, char student_name[100])
{
    struct student_details_linked *current;
    struct student_details_linked *previous = NULL;

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
    while(current->next != NULL && strcmp(current->student_name,student_name)
            != 0)
	{
        previous = current;    
	    current = current->next;
	}

    /* if match is found then following code runs */
    if(strcmp(current->student_name,student_name) == 0)
    {
        /* if prev is unchanged, and current-> next is null there is only one
         * element
         * this deletes element and sets root to NULL */
        if(current->next == NULL && previous == NULL)
        {
            free(current);
            *root = NULL;
            printf("Student removed\n\n");
            return;
        }
        /* if prev is unchanged and current->next is not null, then we delete
         * current and reassign root */
        else if(previous == NULL && current->next != NULL)
        {
            previous = current->next;
            free(current);
            *root = previous;
            printf("Student removed\n\n");
            return;
        }  
        /* otherwise we just delete current and reassign prev pointer to next
         * list element */
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

/* deletes all memebers of linked list + frees memory */
void deleteAllLinked(struct student_details_linked **root)
{
	struct student_details_linked *current;
	struct student_details_linked *previous;

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
void printLinked(struct student_details_linked **root, char student_name[100])
{
    struct student_details_linked *current;

	current = *root;

    while(current->next != NULL && strcmp(current->student_name,student_name)
            != 0)
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

/* asks for file name then saves to that file */
void saveLinked(struct student_details_linked **root, FILE **file)
{
	struct student_details_linked *current;

	current = *root;
    
	while(current != NULL)
	{
        fwrite(current, sizeof(struct student_details_linked), 1, *file);
	    current = current->next;
	}
}

/* asks for file name then reads from file
 * has check if user wasnts to save */
void readLinked(struct student_details_linked **root, FILE **file)
{
    int i;
    int what_do=0;
	struct student_details_linked *current;
	struct student_details_linked *previous = NULL;

	current = *root;

    printf("All unsaved changes will be lost."
            "Would you you like to continue?"
            "\n1.Yes\n2.No\n");
    scanf("%d",&what_do);

    switch(what_do)
    {
        case 1:
            deleteAllLinked(&*root);
        break;
        case 2:
            return;
        break;
    }

    if (*file != NULL)
    {
        current = malloc(sizeof(struct student_details_linked));
        *root = current;
        
        while(fread(current, sizeof(struct student_details_linked), 1, *file))
        {
            i = 1;
            current->next = malloc(sizeof(struct student_details_linked));
            previous = current;
            current = current->next;
        }
        
        if (i == 1)
        {
            previous->next = NULL;
            free(current);
        }
    }
    else
    {
        printf("No file found");
        return;
    }
}

/* adds a new binary students - sorted alphabetically
 * doesn't allow addition of students with the same name */
void newStudentBinary(struct student_details_binary **root, char student_name[100], int student_number)
{
	struct student_details_binary *current;
	struct student_details_binary *previous = NULL;
	struct student_details_binary *new;

    printf("TK: passed to function %s\n", student_name);
    current = *root;

    /* taking input for new entry from user */
	new = malloc(sizeof(struct student_details_binary));
    strcpy(new->student_name, student_name);
	new->student_number = student_number;
    new->right = NULL;
    new->left = NULL;
    printf("TK: new student: %s\n", new->student_name);
    printf("TK: %d\n", new->student_number);

	if(*root == NULL) /* runs if root has no value */ 
	{
	    *root = new;
        return;
    } 
	else	
	{
        /* iterates through list until either: the last element is reached, 
         * or until the strcmp gives a positive value (meaning that the next 
         * element is further down alphabetically  */
        while(current != NULL) 
        {
            if(strcmp(current->student_name, new->student_name) < 0)
            {
                previous = current;
                current = current->right;
            }
            else if(strcmp(current->student_name, new->student_name) == 0)
            {
                printf("\nA student with that name already exists!\n");
                free(new);
                return;
            }
            else if(strcmp(current->student_name, new->student_name) > 0)
            {
                previous = current;
                current = current->left;
            }
        }

       if(strcmp(previous->student_name, new->student_name) < 0)
       {
           previous->right=new;
       }
       else 
       {
           previous->left=new;
       }
    }
}

void rightRotateBinary(struct student_details_binary **current)
{
    struct student_details_binary *temp;
    struct student_details_binary *original;
    struct student_details_binary *left;

    /* checks if node that was passed was null or had no
     * left children */
    if(*current == NULL || (*current)->left == NULL)
    {
        return;
    }

    original = *current;
    left = original->left;

    temp = malloc(sizeof(struct student_details_binary));

    /* copies info from org node to temp */
    strcpy(temp->student_name, original->student_name);
    temp->student_number = original->student_number;

    /* copies info from left node to org node */
    strcpy(original->student_name,left->student_name);
    original->student_number = left->student_number;

    /* copies info from temp to left node */
    strcpy(left->student_name, temp->student_name);
    left->student_number, temp->student_number;

    /* moves temp between the org and right 
     * and saves value of left's left*/
    temp->left = left->right; 
    temp->right = original->right;
    original->left = left->left;
    original->right = temp;

    /* frees old left value */
    free(left);
}

void leftRotateBinary(struct student_details_binary **current)
{
    struct student_details_binary *temp;
    struct student_details_binary *original;
    struct student_details_binary *right;

    /* checks if node that was passed was null or had no
     * right children */
    if(*current == NULL || (*current)->right == NULL)
    {
        return;
    }

    original = *current;
    right = original->right;

    temp = malloc(sizeof(struct student_details_binary));

    /* copies info from org node to temp */
    strcpy(temp->student_name, original->student_name);
    temp->student_number = original->student_number;

    /* copies info from right node to org node */
    strcpy(original->student_name,right->student_name);
    original->student_number = right->student_number;

    /* copies info from temp to right node */
    strcpy(right->student_name, temp->student_name);
    right->student_number = temp->student_number;

    /* moves temp between the org and left 
     * and saves value of right's right*/
    temp->right = right->left; 
    temp->left = original->left;
    original->right = right->right;
    original->left = temp;

    /* frees old right value */
    free(right);
}
    
void balanceBinary(struct student_details_binary **root)
{
    struct student_details_binary *current;
    int expected, i;
    int num_nodes = 0;

    printf("TK: balancing function running \n");
    current = *root;

    while (current != NULL)
    {
        printf("TK: unfolding tree\n");
        while(current->left != NULL)
        {
            rightRotateBinary(&current);
        }
        current = current->right;
        num_nodes++;
    }
    printf("TK: num nodes %d \n", num_nodes);
    expected = num_nodes - (pow(2,(floor(log2(num_nodes+1)))) - 1);
    printf("TK: expected floor nodes %d \n", expected);
    printf("TK: current = %s\n", current ->student_name);
    printf("TK: root = %s\n", (*root)->student_name);
    return;

    current = *root;
    for(i=0; i<expected; i++)
    {
        printf("TK: folding expected nodes\n");
        leftRotateBinary(&current);
        current = current->right;
    }

    current = *root;
    while(current->right != NULL)
    {
        printf("TK: folding odd nodes\n");
        leftRotateBinary(&(current->right));
        current = current->right;
    }
}

/* recursively searches for a student - and if found prints student */
int printBinary(struct student_details_binary **current, char
        student_name[100], int found)
{
	if (*current == NULL)
	{
        return found;
	}
    else
    {
        if(strcmp((*current)->student_name, student_name) == 0)
        {
            found = 1;
            printf("\nStudent name is: %s\n", (*current)->student_name);  
            printf("Student number is: %d\n\n", (*current)->student_number);  
            return found;
        }
        found = printBinary(&(*current)->left, student_name, found);
        found = printBinary(&(*current)->right, student_name, found);
    }
}

/* recursively goes through binary tree and prints all values */
void printAllBinary(struct student_details_binary **root)
{
    struct student_details_binary *current;

	current = *root;

	if (current == NULL)
	{
        return;
	}
    else
    {
        printAllBinary(&current->left);
	    printf("Student name is: %s\n", current->student_name);  
	    printf("Student number is: %d\n\n", current->student_number);  
        printAllBinary(&current->right);
    }
}

/* recursive search function for deletion */
/* checks if root is null or needs to be deleted  */
int deleteBinary(struct student_details_binary **root, struct student_details_binary **current, struct student_details_binary **previous, char student_name[100], int found)
{
    struct student_details_binary *replace;
    struct student_details_binary *replace_previous;
    printf("TK: delete function running\n");
    printf("TK: %d\n", previous);

	if (*current == NULL)
	{
        return found;
	}
    else
    {
        if(strcmp((*current)->student_name, student_name) == 0)
        {
            printf("TK: student found\n");
            found = 1;
            /* runs if root needs to be reassigned */
            if((previous) == NULL)
            {
                printf("TK: changing root\n");
                /* if root node has no children */
                if((*root)->right == NULL && (*root)-> left == NULL)
                {
                    printf("TK: no children\n");
                    free(*root);
                    *root = NULL;
                    return found;
                }

                /* if root node has one child only */
                else if( ((*root)->right == NULL && (*root)->left != NULL) ||
                        ((*root)->right != NULL && (*root)->left == NULL))
                {
                    /* if node has left child */
                    if((*root)->right == NULL && (*root)->left != NULL)
                    {
                        printf("TK: root left child\n");
                        replace = *root;
                        *root = (*root)->left;
                        free(replace);
                        printf("TK: new root: %s\n", (*root)->student_name);
                        return found;
                    }

                    /* if node has right child */
                    else if((*root)->right != NULL && (*root)->left == NULL)
                    {
                        printf("TK: root left child\n");
                        replace = *root;
                        *root = (*root)->right;
                        free(replace);
                        printf("TK: new root: %s\n", (*root)->student_name);
                        return found;
                    }
                }
            }
            /* if current node has no children */
            else if((*current)->right == NULL && (*current)-> left == NULL)
            {
                printf("TK: no children\n");
                if((*previous)->right == *current)
                {
                    (*previous)->right = NULL;
                }
                else if((*previous)->left == *current)
                {
                    (*previous)->left = NULL;
                }
                free(*current);
                return found;
            }

            /* if current node has one child only */
            else if( ((*current)->right == NULL && (*current)->left != NULL) ||
                    ((*current)->right != NULL && (*current)->left == NULL))
            {
                printf("TK: one child\n");
                /* if node has left child */
                if((*current)->right == NULL && (*current)->left != NULL)
                {
                    if ((*previous)->right == *current)
                    {
                        (*previous)->right = (*current)->left;
                    }
                    else if((*previous)->left == *current)
                    {
                        (*previous)->left = (*current)->left;
                    }
                    free(*current);
                    return found;
                }

                /* if node has right child */
                else if((*current)->right != NULL && (*current)->left == NULL)
                {
                    if ((*previous)->right == *current)
                    {
                        (*previous)->right = (*current)->right;
                    }
                    else if((*previous)->left == *current)
                    {
                        (*previous)->left = (*current)->right;
                    }
                    free(*current);
                    return found;
                }
            }

            /* Node has two children */
            else if( (*current)->right != NULL && (*current)->left != NULL)
            {
                printf("TK: two childs\n");
                replace = (*current)->right;
                replace_previous = (*current);

                while(replace->left != NULL)
                {
                    replace_previous = replace;
                    replace = replace->left;
                }
                
                printf("TK: replace right student name %s",replace->student_name);

                strcpy((*current)->student_name,replace->student_name);
                (*current)->student_number = replace->student_number;
                if(replace_previous == (*current))
                {
                    (*current)->right = NULL;
                }
                else
                {
                    replace_previous->left = NULL;
                }

                free(replace);
                return found;
            } 
        }
        deleteBinary(&(*root), &(*current)->left, &(*current), student_name, found);
        deleteBinary(&(*root), &(*current)->right, &(*current), student_name, found);
    }
}

/* deletes all students in binary tree */
void deleteAllBinary(struct student_details_binary **current)
{
    if(*current == NULL)
    {
        return;
    }
    deleteAllBinary(&((*current)->left));
    deleteAllBinary(&((*current)->right));
    printf("TK: Deleting %s\n", (*current)->student_name);
    free(*current);
}

/* recursively goes through database and writes students to file in preorder
 * traversal */
void saveBinary(struct student_details_binary **current, FILE **file)
{
	if (*current == NULL)
    {
        return;
    } 

    fwrite(*current, sizeof(struct student_details_binary), 1, *file);

    saveBinary(&(*current)->left, &(*file));
    saveBinary(&(*current)->right, &(*file));
}

/* reads file and passes each fread to add new student function */
void readBinary(struct student_details_binary **root, FILE **file)
{
    int i;
    int what_do=0;
    char student_name[100];
    struct student_details_binary *current;
    struct student_details_binary *previous;

    printf("All unsaved changes will be lost. "
            "Would you like to continue?"
            "\n1.Yes\n2.No\n");
    scanf("%d",&what_do);

    switch(what_do)
    {
        case 1:
            deleteAllBinary(&(*root));
            *root = NULL;
        break;
        case 2:
            return;
        break;
    }


    if (file != NULL)
    {
        current = malloc(sizeof(struct student_details_binary));
        
        while(fread(current, sizeof(struct student_details_binary), 1, *file))
        {
            printf("TK: %s\n",current->student_name);
            printf("TK: %d\n",current->student_number);
            strcpy(student_name,current->student_name);
            newStudentBinary(&(*root),student_name, current->student_number);
        }
        
        free(current);  
    }

    else
    {
        printf("\nNo file found\n");
        return;
    }
}
