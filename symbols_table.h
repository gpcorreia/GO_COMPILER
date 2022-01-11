#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gocompiler.h"
#define UNDEF "undef"
typedef struct varTab
{
    char *value;
    char *type;
    int isParam;
    int isUsed;
    int line;
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

int semantic_errors;

funcDecl *create_node_func(Tree *funcHeader_content);
varDecl *create_node_var(Tree *varDecl_content);
Tree *insert_Symbol_Table(funcDecl *functionl, varDecl *var);
void anoted_tree(Tree *body);
varDecl *check_vars_global(char *value);
funcDecl *check_func_simbols_table(char *value);
varDecl *find_var_in_function(Tree *head);
char *prepare_to_print_error_params(Tree *node, int posicion);
int check_params(Tree *call, funcDecl *func);
int check_exist_token(char *string);
int check_var_exist(char *string, varDecl *lista_var);
char *tolower_string(char *string);
char *string_params_func(varDecl *vars_params);
int handle_semantic_errors(int line, int column, char *symbol, char *value, char *value2);
char *clear_string_to_error(char *string);

#endif