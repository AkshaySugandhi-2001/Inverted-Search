#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 1
#define FAILURE 0
#define NOT_AVAILABLE 2
#define REPEAT -1

typedef struct main_node
{
    char word[50];
    int file_count;
    struct main_node *Mlink;
    struct Sub_node *Slink;
}M_node;


typedef struct Sub_node
{
    int word_count;
    char filename[50];
    struct Sub_node *Slink;
}S_node;


typedef struct filename
{
    char file[20];
    struct filename *link;
}Slist;
int read_and_validate(Slist **filename, char *argv[]);
int file_empty(char *filename);
int store_filename(Slist **filename , char *fname);
int create_database(Slist **filename, M_node *arr[]);
int display_database(M_node *arr[]);
int search_word(M_node *arr[]);
int save_file(M_node *arr[]);
int update_database(M_node *arr[],Slist **filename);
M_node *create_main_node(char *word,char *filename);
S_node *create_sub_node(char *filename);
int insert_last(Slist **head,char *file_name);
int check(char *filename, Slist **head);

int sl_delete_element(Slist **head, char *filename);

#endif
