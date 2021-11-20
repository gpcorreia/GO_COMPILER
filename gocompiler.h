#ifndef GOCOMPILER_H
#define GOCOMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define MAX_STRING 100

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
Tree *cicleFor(Tree *condicions, Tree *content);
Tree *add1child(Tree *parent, Tree *value1);
Tree *add3child(Tree *parent, Tree *value1, Tree *value2, Tree *value3);

void showList();

#endif