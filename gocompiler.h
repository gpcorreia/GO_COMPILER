#ifndef GOCOMPILER_H
#define GOCOMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX_STRING 100
#define MAX_VALUE 100

typedef struct Token
{
    char *token;
    int line;
    int column;
} TOKEN;

typedef struct tree
{
    char *token;
    char *value;
    struct tree *next;
    struct tree *child;
} Tree;

Tree *createNode(char *token, char *value);
Tree *addchild(Tree *parent, Tree *value1, Tree *value2);
Tree *addbro(Tree *head, Tree *bro);
Tree *createFuncDecl(Tree *id, Tree *params, Tree *type, Tree *funcBody);
Tree *cicleIf(Tree *condicions, Tree *content, Tree *contentElse);
Tree *createListId(Tree *listIds, Tree *type);
Tree *cicleFor(Tree *condicions, Tree *content);
Tree *returnNode(Tree *node);
Tree *strNode(Tree *str);
Tree *add1child(Tree *parent, Tree *value1);
void showList(Tree *root, int depth);

#endif