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

int save_file(M_node *arr[])
{
    char new_file[100];
    printf("Enter the filename\n");
    scanf("%s",new_file);
    FILE *fptr =fopen(new_file,"w");
    if(strcmp(strstr(new_file,"."),".txt") != 0)
    {
	printf("It is not a txt file\n");
    }
    else
    {

    for (int i = 0; i < 27; i++)
    {
	if(arr[i] != NULL)
	{
	    M_node *temp = arr[i];
	    while (temp != NULL)
	    {

		S_node *temp1 = temp->Slink;
		while (temp1 != NULL)
		{
		    fprintf(fptr,";%s;%d;",temp1->filename,temp1->word_count);
		    temp1 = temp1->Slink;
		}

		fprintf(fptr,"%s\n","#");
		temp = temp->Mlink;
	    }
	}

    }
    }
    fclose(fptr);
    return SUCCESS;
}
