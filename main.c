/*
Name:Shafiulla
Date://2023
Description:
Sample Input:
Sample Output:
*/
#include<stdio.h>
#include<string.h>
#include "sll.h"
int main(int argc , char *argv[])
{
    M_node *arr[27] = {NULL};
    int i=1,flag=0;
    Slist *filename= NULL;
    if(argc > 1)
    {
	if(read_and_validate(&filename,argv) == SUCCESS)
	{
	    printf("Read and validation is successfully done\n");
	    while(1)
	    {
		int choice;
		printf("1. Create database\n2. Display\n3. Search word\n4. Save database\n5.Update database\n6. exit\n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		    case 1:
			if(flag == 0)
			{
			if(create_database(&filename,arr)== SUCCESS)
			{
			    printf("Database created Successfully\n");
			}
			else
			{
			    printf("FAILED to create database\n");
			}
			flag=1;
			}
			else
			{
			    printf("cant create database already updated\n");
			}
			break;
		    case 2:
			if(display_database(arr) == SUCCESS)
			{
			    printf("display data successfull\n");
			}
			else
			{
			    printf("Failed to display database\n");
			}
			break;
		    case 3:
			if(search_word(arr) == SUCCESS)
			{
			    printf("word searched successfully\n");
			}
			else
			{
			    printf("FAILED to search word\n");
			}
			break;
		    case 4:
			if(save_file(arr)== SUCCESS)
			{
			    printf("Save file is a success\n");
			}
			else
			{
			    printf("Failed to save file\n");
			}
			break;
		    case 5:
			if(flag == 0)
			{
			if(update_database(arr,&filename) == SUCCESS)
			{
			    printf("Database updated succesfully\n");
			}
			else
			{
			    printf("Failed to update database\n");
			}
			flag =1;
			}
			else
			{
			    printf("create database is done cant update\n");
			}
			break;
		    case 6:
			return 0;
		    default:
			printf("INFO: ERROR\n");
		}
	    }
	}
	else
	{
	    printf("Failed to read and validate\n");
	}
    }
    else
    {
	printf("No command line arguments passed\n");
    }
}


int read_and_validate(Slist **filename, char **argv)
{
    int i =1;
    for(i=1;argv[i]!=NULL;i++)
    {
	if(strstr(argv[i],".txt") != NULL)
	{
	   // printf("it is .txt\n");
	    if(file_empty(argv[i]) == NOT_AVAILABLE)
	    {
		printf("File is not present\n");
		continue;
	    }
	    else if(file_empty(argv[i]) == SUCCESS)
	    {
		printf("File is empty\n");
		continue;
	    }
	    else
	    {
		printf("file present\n");
		if(store_filename(filename,argv[i]) == SUCCESS)
		{
		    printf("File name stored successfully\n");
		   // return SUCCESS;
		}
		else if(store_filename(filename,argv[i]) == REPEAT)
		{
		    printf("File is repeated\n");
		    continue;
		    
		}
		else
		{
		    printf("Failed to store the filenames\n");
		    return FAILURE;
		}
	    }
	}
	else
	{
	printf("not a .txt file \n");
	return FAILURE;
	}
    }
    return SUCCESS;

}

int file_empty(char *filename)
{
    FILE *fptr= fopen(filename,"r");
    if(fptr == NULL)
    {
	return NOT_AVAILABLE;
    }
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0)
    {
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}


int store_filename(Slist **filename , char *fname) 
{
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->file, fname);
    new->link = NULL;
    if(*filename == NULL)
    {
        *filename = new;
        printf("Stored filename: %s\n", fname); 
        return SUCCESS;
    }
    Slist *temp = *filename;
    Slist *prev = NULL;

    while(temp != NULL)
    {
        if(strcmp(temp->file , new->file) == 0) {
            return REPEAT;
        }
        prev = temp;
        temp = temp->link;
    }
    prev ->link = new;
    printf("Stored filename: %s\n", fname); 
    return SUCCESS;
}



		    



