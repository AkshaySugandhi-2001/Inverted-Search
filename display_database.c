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

int display_database(M_node *arr[]) 
{
    printf("[Index]\tword\tfilecount\tfilename\twordcount\n");

    for (int i = 0; i < 27; i++) 
    {
        M_node *temp = arr[i];
        while (temp != NULL) 
	{
            printf("%d\t", i); 
            printf("%s\t", temp->word); 
            printf("%d\t", temp->file_count); 

           
            S_node *temp1 = temp->Slink;
            while (temp1 != NULL) 
	    {
                printf("%s\t", temp1->filename); 
                printf("%d\t", temp1->word_count); 
                temp1 = temp1->Slink;
            }

            printf("\n");
            temp = temp->Mlink; 
        }
    }
	return SUCCESS;
}

