#ifndef gocompiler
#define gocompiler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 100

typedef struct newnode
{
    char token[MAX_STRING];
    char value[MAX_STRING];
    struct newnode *next;
} Tree;

Tree *head = NULL;

Tree *addNode(char *token, char *value);
void showList();

#endif