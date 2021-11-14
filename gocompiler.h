#ifndef gocompiler
#define gocompiler

#include <stdio.h>
#include <stdlib.h>

typedef struct newnode
{
    char *token;
    char *value;
    struct newnode *next;
} Tree;

Tree *head;

#endif