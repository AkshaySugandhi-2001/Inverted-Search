/*
Name:Shafiulla
Date://2023
Description:
Sample Input:
Sample Output:
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "sll.h"
int create_database(Slist **filename, M_node *arr[]) 
{
    int index;
    Slist *temp = *filename;
   /* M_node *t = arr[index];
        // Check if the file already exists in the database
        int file_exists = 0;
        while (t != NULL) {
            S_node *s_temp = t->Slink;
            while (s_temp != NULL) {
                if (strcmp(s_temp->filename, t->) == 0) {
                    // File already exists in the database, set flag and exit loop
                    file_exists = 1;
                    break;
                }
                s_temp = s_temp->Slink;
            }
            t = t->Mlink;
        }*/

    while(temp) 
    {
        FILE *fptr = fopen(temp->file, "r");
        if(fptr == NULL)
       	{
            printf("failed to open file: %s\n", temp->file);
            temp = temp->link; 
            continue;
        } 
	else 
	{
            printf("Successfully opened file: %s\n", temp->file);
        }
        char word[40];
        while(fscanf(fptr,"%s",word) != EOF) 
	{
            if(word[0] >= 'a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z') 
	    {
                index= toupper(word[0]) % 65;
            } 
	    else 
	    {
                index = 26;
            }
           // printf("Word: %s, Index: %d\n", word, index);

            if(arr[index] == NULL) 
	    {
                arr[index] = create_main_node(word,temp->file);
            } 
	    else 
	    {
              
                M_node *temp1 = arr[index];
                M_node *prev1 = NULL;
                S_node *temp2 = NULL;
                S_node *prev2 = NULL;

                while(temp1 != NULL) 
		{
                    if(strcmp(temp1->word,word) == 0) 
		    {
                     
                        temp2 = temp1->Slink;
                        while(temp2 != NULL)
		       	{
                            if(strcmp(temp2->filename , temp->file)==0) 
			    {
                                (temp2->word_count)++;
                                break;
                            }
                            prev2 = temp2;
                            temp2 = temp2->Slink;
                        }
                        if(temp2 == NULL) 
			{
                            prev2->Slink = create_sub_node(temp->file);
                            (temp1->file_count)++;
                        }
                        break;
                    }
                    prev1 = temp1;
                    temp1 = temp1->Mlink;
                }
                if(temp1 == NULL) 
		{
                    prev1->Mlink = create_main_node(word , temp->file);
                }
            }
        }
        fclose(fptr);
        temp = temp->link;
    }
    return SUCCESS;
}

M_node *create_main_node(char *word, char *filename)
{
    M_node *new = malloc(sizeof(M_node));
    if(new == NULL)
    {
        return NULL;
    }
    strcpy(new->word , word);
    new->file_count =1;
    new->Mlink = NULL;
    new->Slink= create_sub_node(filename);
    return new;
}

S_node *create_sub_node(char *filename)
{
    S_node *new = malloc(sizeof(S_node));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->word_count =1;
    strcpy(new->filename,filename);
    new->Slink = NULL;
    return new;
}

