#include "gocompiler.h"
#include "symbols_table.h"

extern table_elem *symbols_table;

funcDecl *create_node_func(Tree *funcHeader_content)
{
    Tree *aux = funcHeader_content->child;
    Tree *funcBodyContent = funcHeader_content->next->child;

    funcDecl *newFuncNode = (funcDecl *)malloc(sizeof(funcDecl));
    // varDecl *listVarDecl = (varDecl *)malloc(sizeof(varDecl)); // lista ligada de variaveis da funcao
    varDecl *lastList = NULL;

    if (check_exist_token(aux->value) == 1)
    {
        printf("Variavel existente\n");
        return NULL;
    }

    newFuncNode->value = aux->value;

    aux = aux->next;

    if (strcmp(aux->token, "FuncParams") != 0)
    {
        newFuncNode->return_type = tolower_string(aux->token);
        aux = aux->next->child;
    }

    else
        aux = aux->child;

    // FuncParams
    while (aux != NULL)
    {
        varDecl *listVarDecl = (varDecl *)malloc(sizeof(varDecl));
        listVarDecl->value = aux->child->next->value;
        listVarDecl->type = tolower_string(aux->child->token);
        listVarDecl->isParam = 1;
        listVarDecl->next = NULL;

        if (newFuncNode->vars == NULL)
        {
            newFuncNode->vars = listVarDecl;
            lastList = newFuncNode->vars;
        }

        else
        {
            lastList->next = listVarDecl;
            lastList = lastList->next;
            // newFuncNode->vars = lastList;
        }

        aux = aux->next;
    }

    // funcbody
    while (funcBodyContent != NULL)
    {
        if (strcmp(funcBodyContent->token, "VarDecl") == 0)
        {
            if (check_var_exist(funcBodyContent->child->next->value, newFuncNode->vars) == 0)
            {
                varDecl *listVarDecl = (varDecl *)malloc(sizeof(varDecl));
                listVarDecl->value = funcBodyContent->child->next->value;
                listVarDecl->type = tolower_string(funcBodyContent->child->token);
                listVarDecl->isParam = 0;
                listVarDecl->next = NULL;

                if (newFuncNode->vars == NULL)
                {
                    newFuncNode->vars = listVarDecl;
                    lastList = newFuncNode->vars;
                }

                else
                {
                    lastList->next = listVarDecl;
                    lastList = lastList->next;
                }
            }
        }

        funcBodyContent = funcBodyContent->next;
    }

    return newFuncNode;
}

varDecl *create_node_var(Tree *varDecl_content)
{

    Tree *aux = varDecl_content;
    varDecl *newNodeVar = (varDecl *)malloc(sizeof(varDecl));
    if (check_exist_token(aux->next->value) == 1)
    {
        printf("a\n");
        return NULL;
    }
    newNodeVar->value = aux->next->value;
    newNodeVar->type = tolower_string(aux->token);
    newNodeVar->isParam = 0;
    newNodeVar->next = NULL;
    return newNodeVar;
}

Tree *insert_Symbol_Table(funcDecl *functionl, varDecl *var)
{
    table_elem *aux = symbols_table;
    // add vardecl to table
    if (!functionl)
    {

        table_elem *newNode = (table_elem *)malloc(sizeof(symbols_table));
        if (symbols_table == NULL)
        {
            newNode->var = var;
            symbols_table = newNode;
        }
        else
        {
            newNode->var = var;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    }

    else
    { // add function to table
        table_elem *newNode = (table_elem *)malloc(sizeof(symbols_table));

        if (symbols_table == NULL)
        {
            newNode->func = functionl;
            symbols_table = newNode;
        }
        else
        {
            newNode->func = functionl;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    }
}

int check_exist_token(char *string)

{
    table_elem *aux = symbols_table;

    if (symbols_table == NULL)
    {
        return 0;
    }
    else
    {
        while (aux->next != NULL)
        {
            if (aux->func != NULL)
            {
                if (strcmp(aux->func->value, string) == 0)
                {
                    return 1;
                }
            }
            else
            {
                printf("%s------- %s\n", aux->var->value, string);
                if (strcmp(aux->var->value, string) == 0)
                {
                    return 1;
                }
            }
            aux = aux->next;
        }
    }

    return 0;
}

int check_var_exist(char *string, varDecl *lista_var)
{
    varDecl *list_var = lista_var;

    while (list_var != NULL)
    {
        if (strcmp(string, list_var->value) == 0)
        {
            return 1;
        }
        list_var = list_var->next;
    }
    return 0;
}

char *tolower_string(char *string)
{
    char *newString = malloc(sizeof(char) * MAX_STRING);
    strcpy(newString, string);

    for (int i = 0; i < strlen(string); i++)
    {
        if (newString[i] >= 65 && newString[i] <= 90)
            newString[i] = newString[i] + 32;
    }

    return newString;
}