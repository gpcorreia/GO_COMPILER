#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gocompiler.h"
#include "semantics.h"

typedef struct varTab
{
    char *value;
    char *type;
    int isParam;
    struct varTab *next;
} varDecl;

typedef struct funcDecl
{
    char *value;
    char *return_type;
    varDecl *vars;

} funcDecl;

typedef struct elem
{
    varDecl *var;
    funcDecl *func;
    struct elem *next;
} table_elem;

funcDecl *create_node_func(Tree *funcHeader_content);
varDecl *create_node_var(Tree *varDecl_content);
Tree *insert_Symbol_Table(funcDecl *functionl, varDecl *var);
int check_exist_token(char *string);
int check_var_exist(char *string, varDecl *lista_var);
char *tolower_string(char *string);

#endif