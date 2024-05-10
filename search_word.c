/*
Name:Shafiulla
Date://2023
Description:
Sample Input:
Sample Output:
*/

#include <stdio.h>
#include <string.h>
#include "sll.h"

int search_word(M_node *arr[]) 
{
    char search_word[50];
    printf("Enter the word to search: ");
    scanf("%s", search_word);

    int found = 0;

    for (int i = 0; i < 27; i++) 
    {
        M_node *temp = arr[i];
        while (temp != NULL)
       	{
            if (strcmp(temp->word, search_word) == 0)
	        {
                printf("Main Node: %s\n", temp->word);
                printf("File Count: %d\n", temp->file_count);

                S_node *subnode = temp->Slink;
                while (subnode != NULL) 
		        {
                    printf("File Name: %s\n", subnode->filename);
                    printf("Word Count: %d\n", subnode->word_count);
                    subnode = subnode->Slink;
                }

                break;    
            }
            temp = temp->Mlink; 
        }
    }

    return SUCCESS;
}


