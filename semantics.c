#include "semantics.h"

table_elem *check_root(Tree *head)
{
    Tree *aux = head;

    aux = aux->child;
    while (aux != NULL)
    {
        if (strcmp(aux->token, "VarDecl") == 0)
            insert_Symbol_Table(NULL, check_var_decl(aux->child));

        else // if (strcmp(aux->token, "FuncDecl") == 0)
            insert_Symbol_Table(check_func_decl(aux->child), NULL);

        aux = aux->next;
    }

    return symbols_table;
}

varDecl *check_var_decl(Tree *varDecl_node)
{
    return create_node_var(varDecl_node);
}

funcDecl *check_func_decl(Tree *funcHeader)
{

    return create_node_func(funcHeader); // Fornecer funcHeader para criar a estrutura func
}

void print_tabel(table_elem *root)
{
    table_elem *aux = root;

    printf("===== Global Symbol Table =====\n");
    while (aux != NULL)
    {
        if (aux->func)
        {
            if (aux->func->vars != NULL && aux->func->vars->isParam == 1)
            {
                if (aux->func->return_type != NULL)
                    printf("%s\t(%s)\t%s\n", aux->func->value, string_params_func(aux->func->vars), aux->func->return_type);

                else
                {
                    printf("%s\t(%s)\tnone\n", aux->func->value, string_params_func(aux->func->vars));
                }
            }
            else
            {
                if (aux->func->return_type != NULL)
                    printf("%s\t()\t%s\n", aux->func->value, aux->func->return_type);

                else
                    printf("%s\t()\tnone\n", aux->func->value);
            }
        }
        else
        {

            printf("%s\t%s\n", aux->var->value, aux->var->type);
        }
        aux = aux->next;
    }

    aux = root;
    while (aux != NULL)
    {
        if (!aux->var)
        {
            if (aux->func->vars != NULL && aux->func->vars->isParam == 0)
            {
                if (!aux->func->return_type)
                {
                    printf("===== Function %s () Symbol Table =====\n", aux->func->value);
                    printf("return\t\tnone\n");
                }
                else
                {
                    printf("===== Function %s () Symbol Table =====\n", aux->func->value);
                    printf("return\t\t%s\n", aux->func->return_type);
                }
            }
            else if (aux->func->vars == NULL)
            {
                if (!aux->func->return_type)
                {
                    printf("===== Function %s () Symbol Table =====\n", aux->func->value);
                    printf("return\t\tnone\n");
                }
                else
                {
                    printf("===== Function %s () Symbol Table =====\n", aux->func->value);
                    printf("return\t\t%s\n", aux->func->return_type);
                }
            }
            else
            {
                if (!aux->func->return_type)
                {
                    printf("===== Function %s (%s) Symbol Table =====\n", aux->func->value, string_params_func(aux->func->vars));
                    printf("return\t\tnone\n");
                }
                else
                {
                    printf("===== Function %s (%s) Symbol Table =====\n", aux->func->value, string_params_func(aux->func->vars));
                    printf("return\t\t%s\n", aux->func->return_type);
                }
            }

            while (aux->func->vars != NULL)
            {
                if (aux->func->vars->isParam == 0)
                {
                    printf("%s\t%s\t\n", aux->func->vars->value, aux->func->vars->type);
                }
                else
                {
                    printf("%s\t\t%s\tparam\n", aux->func->vars->value, aux->func->vars->type);
                }

                aux->func->vars = aux->func->vars->next;
            }
        }

        aux = aux->next;
        printf("\n");
    }
}

char *string_params_func(varDecl *vars_params)
{

    char *newString = malloc(sizeof(char) * MAX_STRING);
    varDecl *aux = vars_params;

    if (aux->next == NULL)
    {
        return aux->type;
    }

    while (aux != NULL)
    {
        if (aux->isParam == 1)
        {
            strcat(newString, aux->type);
            if (aux->next != NULL)
            {
                strcat(newString, ",");
            }
        }
        aux = aux->next;
    }
    return newString;
}