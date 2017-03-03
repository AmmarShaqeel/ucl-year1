#include<stdio.h>
#include<string.h>

char my_strcpy(char *copy, char *org)
{
	int i; 
	for(i = 0; i <= (strlen(org)); i++)
	{
		copy[i] = org[i];
	}
}

int my_strcmp(char *compare, char *org)
{
	int i, c = 0, size;
	
	if(strlen(compare)>strlen(org))
	{
		size = strlen(compare);
	}
	else
	{
		size = strlen(org);
	}
	
	for(i = 0; i <= (size+1); i++)
	{
		if(compare[i] != org[i])
		{
			c = compare[i]-org[i];
			break;
		}
	}
	
	return c;
}

int main()
{
	int my_is_same;
	
	char org[11] = "a";
	char copy[40] = "b";

	
	my_is_same = my_strcmp(copy,org);
	my_strcpy(copy,org);
	
	printf("my strcpy: %i\n",my_is_same);
	
	printf("%s\n",org);
	printf("%s\n",copy);
	// printf("%s",returnstring());
	
	return 0;
}


