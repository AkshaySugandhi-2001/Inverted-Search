/*
Name:Shafiulla
Date://2023
Description:
Sample Input:
Sample Output:
 */
#include "sll.h"
#include<string.h>
#include<stdio.h>
int update_database(M_node *arr[], Slist **filename)
{
    int index;
    Slist *head = NULL;
    char back_file[30];
    printf("Enter the file you want to update\n");
    scanf("%s",back_file);
    FILE *fptr = fopen(back_file,"r");
    if(strcmp(strstr(back_file,"."),".txt") != 0)
    {
	printf("not a .txt file\n");

    }
    else
    {
	char bfile_line[100];
	char word[20];
	FILE *fptr = fopen(back_file,"r");
	if(fptr == NULL)
	{
	    return FAILURE;
	}

	while(fscanf(fptr,"%s",bfile_line) != EOF)
	{
	    if(bfile_line[0] != '#')
	    {
		return FAILURE;
	    }
printf("1\n");
	    index = atoi(strtok(bfile_line,";#"));
	    M_node *M_new = malloc(sizeof(M_node));
	    if(M_new == NULL)
	    {
		return FAILURE;
	    }
	    strcpy(M_new -> word, strtok(NULL,"#;"));
	    M_new -> file_count = atoi(strtok(NULL,"#;"));
	    M_new -> Mlink = NULL;

	    S_node *S_new = malloc(sizeof(S_node));


	    if(S_new == NULL)
	    {
		return FAILURE;
	    }

	    strcpy(S_new -> filename, strtok(NULL,"#;"));
	    //if(sl_delete_element(filename,S_new->filename) == SUCCESS)
	
	    {
		insert_last(&head,S_new->filename);
		S_new -> word_count = atoi(strtok(NULL,"#;"));
		S_new -> Slink = NULL;
		M_new -> Slink = S_new;
		S_node *S_temp =S_new;

		for(int i=0; i<(M_new->file_count)-1;i++)
		{
		    S_node *S_new = malloc(sizeof(S_node));
		    if(S_new == NULL)
			return FAILURE;
		    strcpy(S_new -> filename, strtok(NULL,"#;"));
		    insert_last(&head,S_new->filename);
		    S_new -> word_count = atoi(strtok(NULL,"#;"));
		    S_new -> Slink = NULL;
		    S_temp -> Slink = S_new;
		    S_temp = S_new;
		}


		M_node *temp = arr[index];
		if(temp == NULL)
		{
		    arr[index] = M_new;
		}
		else
		{
		    while(temp -> Mlink)
		    {
			temp = temp->Mlink;
		    }
		    temp ->Mlink = M_new;
		}
	    }
	   
	}
	    fclose(fptr);
	    return SUCCESS;
    }
}

int insert_last(Slist **head, char file_name[])
{
    if(*head == NULL)
    {
	Slist *new = malloc(sizeof(Slist));
	if(new == NULL)
	    return FAILURE;
	strcpy(new -> file, file_name);
	new -> link = NULL;
	*head = new;
    }
    else
    {
	Slist *temp = *head;
	Slist *prev;
	while(temp != NULL)
	{
	    prev =temp;
	    temp = temp -> link;
	}
	Slist *new = malloc(sizeof(Slist));
	if(new == NULL)
	    return FAILURE;
	strcpy(new -> file,file_name);
	new -> link = NULL;
	prev -> link = new;
    }


    return SUCCESS;
}

int check(char *filename , Slist **head)
{
    Slist *t = *head;
    while(t != NULL)
    {
	if(strcmp(filename ,t->file) == 0)
	{
	   // printf("file already present\n");
	    return FAILURE;
	}
	t = t->link;
    }
    return SUCCESS;


}

int sl_delete_element(Slist **head, char *filename)
{
    if(*head == NULL) // check whether list is empty or not
    return FAILURE;
    
    Slist *cur=*head;
    Slist *prev= NULL;
    
    if(cur-> file == filename) // check wheter data is eual to given data
        {
            *head = cur->link; // traverse
            free(cur);// delete element
        }
        
    while(cur->link != NULL) //loop upto cur reaches null
    {
        if(cur->file != filename)//curent data not equal to given data
        {
            prev=cur;
            cur= cur->link;
        }
        else
        {
            prev->link=cur->link;
            free(cur);
       }
  }


}
