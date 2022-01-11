#include "gocompiler.h"
#include "symbols_table.h"

extern table_elem *symbols_table;

char *funcDeclaracion;

funcDecl *create_node_func(Tree *funcHeader_content)
{
    Tree *aux = funcHeader_content->child;
    Tree *funcBodyContent = funcHeader_content->next->child;

    funcDecl *newFuncNode = (funcDecl *)malloc(sizeof(funcDecl));
    // varDecl *listVarDecl = (varDecl *)malloc(sizeof(varDecl)); // lista ligada de variaveis da funcao
    varDecl *lastList = NULL;

    if (check_exist_token(aux->value) == 1)
    {
        printf("Line %d, column %d: Symbol %s already defined\n", aux->line, aux->column, aux->value);
        semantic_errors = 1;
        return NULL;
    }

    newFuncNode->value = aux->value;
    funcDeclaracion = aux->value;

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
        listVarDecl->isUsed = 0;
        listVarDecl->line = aux->child->line;
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
                listVarDecl->isUsed = 0;
                listVarDecl->line = funcBodyContent->child->line;

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
        printf("Line %d, column %d: Symbol %s already defined\n", aux->next->line, aux->next->column, aux->next->value);
        semantic_errors = 1;
        return NULL;
    }
    newNodeVar->value = aux->next->value;
    newNodeVar->type = tolower_string(aux->token);
    newNodeVar->isParam = 0;
    newNodeVar->isUsed = 0;
    newNodeVar->line = aux->line;
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
    return NULL;
}

void anoted_tree(Tree *body)
{
    if (body == NULL)
    {
        return;
    }

    else if (strcmp(body->token, "Id") == 0)
    {
        varDecl *aux_in_func = find_var_in_function(body);
        if (aux_in_func == NULL)
        {
            varDecl *aux_global = check_vars_global(body->value);

            if (aux_global == NULL)
            {
                funcDecl *aux2 = check_func_simbols_table(body->value);
                if (aux2 != NULL)
                {
                    char *newString = (char *)malloc(sizeof(char));
                    strcat(newString, "(");
                    if (string_params_func(aux2->vars) == NULL)
                    {
                        strcat(newString, ")");
                    }
                    else
                    {
                        strcat(newString, string_params_func(aux2->vars));
                        strcat(newString, ")");
                    }

                    body->print = newString;
                }
            }
            else
            {
                body->print = aux_global->type;
            }
        }
        else
        {
            // printf("%s------------\n", aux_in_func->value);
            body->print = aux_in_func->type;
        }
    }

    else if (strcmp(body->token, "ParseArgs") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) == 0 && strcmp(body->child->print, "int") == 0)
            body->print = body->child->print;

        else
            handle_semantic_errors(body->line, body->column, "strconv.Atoi", body->child->print, body->child->next->print);
    }

    else if (strcmp(body->token, "Or") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && strcmp(body->child->print, "bool") != 0)
            handle_semantic_errors(body->line, body->column, "||", body->child->print, body->child->next->print);
    }

    else if (strcmp(body->token, "And") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 || strcmp(body->child->print, "bool") != 0)
            handle_semantic_errors(body->line, body->column, "&&", body->child->print, body->child->next->print);
    }

    else if (strcmp(body->token, "Eq") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "bool") != 0 || strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))

            handle_semantic_errors(body->line, body->column, "==", body->child->print, body->child->next->print);
    }

    else if (strcmp(body->token, "Ne") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "bool") != 0 || strcmp(body->child->next->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))
            handle_semantic_errors(body->line, body->column, "!=", body->child->print, body->child->next->print);
    }

    else if (strcmp(body->token, "Lt") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (body->child->print == NULL || body->child->next->print == NULL)
        {
            handle_semantic_errors(body->line, body->column, "<", body->child->print, body->child->next->print);
        }
        else
        {
            if (strcmp(body->child->print, body->child->next->print) != 0 || strcmp(body->child->print, "bool") == 0)
            {
                handle_semantic_errors(body->line, body->column, "<", body->child->print, body->child->next->print);
            }
        }
    }

    else if (strcmp(body->token, "Gt") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (body->child->print == NULL || body->child->next->print == NULL)
        {
            handle_semantic_errors(body->line, body->column, ">", body->child->print, body->child->next->print);
        }
        else
        {
            if (strcmp(body->child->print, body->child->next->print) != 0 || strcmp(body->child->print, "bool") == 0)
            {
                handle_semantic_errors(body->line, body->column, ">", body->child->print, body->child->next->print);
            }
        }
    }

    else if (strcmp(body->token, "Le") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (body->child->print == NULL || body->child->next->print == NULL)
        {
            handle_semantic_errors(body->line, body->column, "<=", body->child->print, body->child->next->print);
        }
        else
        {
            if (strcmp(body->child->print, body->child->next->print) != 0 || strcmp(body->child->print, "bool") == 0)
            {
                handle_semantic_errors(body->line, body->column, "<=", body->child->print, body->child->next->print);
            }
        }
    }

    else if (strcmp(body->token, "Ge") == 0)
    {

        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (body->child->print == NULL || body->child->next->print == NULL)
        {
            handle_semantic_errors(body->line, body->column, ">=", body->child->print, body->child->next->print);
        }
        else
        {
            if (strcmp(body->child->print, body->child->next->print) != 0 || strcmp(body->child->print, "bool") == 0)
            {
                handle_semantic_errors(body->line, body->column, ">=", body->child->print, body->child->next->print);
            }
        }
    }

    else if (strcmp(body->token, "Call") == 0)
    {
        if (body->next)
        {
            if (body->next->print == NULL)
            {
                anoted_tree(body->next);
            }
        }

        funcDecl *aux = check_func_simbols_table(body->child->value);

        if (aux == NULL)
        {
            printf("Line %d, column %d: Cannot find symbol %s()\n", body->line, body->column, body->value);
            semantic_errors = 1;
        }
        else
        {
            anoted_tree(body->child);
            int posicion = check_params(body, aux);

            if (posicion == 0)
            {
                body->print = aux->return_type;
            }
            else
            {
                char *newString = prepare_to_print_error_params(body, posicion);
                printf("Line %d, column %d: Cannot find symbol %s(%s)\n", body->line, body->column, body->child->value, newString);
                semantic_errors = 1;
            }
        }
    }

    else if (strcmp(body->token, "Assign") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);
        // anoted_tree(body->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0 || strcmp(body->child->print, "bool") != 0))
            handle_semantic_errors(body->line, body->column, "=", body->child->print, body->child->next->print);
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Mod") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && strcmp(body->child->print, "int") != 0)
        {
            handle_semantic_errors(body->line, body->column, "%", body->child->print, body->child->next->print);
            body->print = UNDEF;
        }
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Add") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))
        {
            handle_semantic_errors(body->line, body->column, "+", body->child->print, body->child->next->print);
            body->print = UNDEF;
        }
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Sub") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))
        {
            handle_semantic_errors(body->line, body->column, "-", body->child->print, body->child->next->print);
            body->print = UNDEF;
        }
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Mul") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);
        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))
        {
            handle_semantic_errors(body->line, body->column, "*", body->child->print, body->child->next->print);
            body->print = UNDEF;
        }
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Div") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);
        if (strcmp(body->child->print, body->child->next->print) != 0 && (strcmp(body->child->print, "int") != 0 || strcmp(body->child->print, "float32") != 0))
        {
            handle_semantic_errors(body->line, body->column, "/", body->child->print, body->child->next->print);
            body->print = UNDEF;
        }
        else
            body->print = body->child->print;
    }

    else if (strcmp(body->token, "Plus") == 0)
    {
        anoted_tree(body->child);

        if (body->child)
        {
            if (strcmp(body->child->print, "bool") != 0)
            {
                body->print = body->child->print;
            }
        }
    }

    else if (strcmp(body->token, "Minus") == 0)
    {
        anoted_tree(body->child);

        if (body->child)
        {
            if (strcmp(body->child->print, "bool") != 0)
            {
                body->print = body->child->print;
            }
        }
    }

    else if (strcmp(body->token, "If") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, "bool") != 0)
        {
            printf("Line %d, column %d: Incompatible type %s in if statement\n", body->line, body->column, body->child->print);
            semantic_errors = 1;
        }
    }

    else if (strcmp(body->token, "For") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->child->next);

        if (strcmp(body->child->print, "bool") != 0)
        {
            printf("Line %d, column %d: Incompatible type %s in for statement\n", body->line, body->column, body->child->print);
            semantic_errors = 1;
        }
    }

    else if (strcmp(body->token, "Not") == 0)
    {
        anoted_tree(body->child);

        if (strcmp(body->child->print, "bool") != 0)
        {
            printf("Line %d, column %d: Operator %s cannot be applied to type %s\n", body->line, body->column, body->value, body->child->print);
            semantic_errors = 1;
        }
    }

    else if (strcmp(body->token, "Return") == 0)
    {
        anoted_tree(body->child);
    }

    else if (strcmp(body->token, "Print") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->next);

        anoted_tree(body->child->next);
    }

    else if (strcmp(body->token, "Block") == 0)
    {
        anoted_tree(body->child);
        anoted_tree(body->next);
    }
}

varDecl *check_vars_global(char *value)
{
    table_elem *aux = symbols_table;

    while (aux != NULL)
    {
        if (aux->var)
        {
            varDecl *VarFind = aux->var;
            while (VarFind != NULL)
            {
                if (strcmp(aux->var->value, value) == 0)
                {
                    return VarFind;
                }
                VarFind = VarFind->next;
            }
        }
        aux = aux->next;
    }

    return NULL;
}

funcDecl *check_func_simbols_table(char *value)
{
    table_elem *aux = symbols_table;

    if (value == NULL)
    {
        return NULL;
    }

    while (aux != NULL)
    {
        if (aux->func)
        {
            if (strcmp(value, aux->func->value) == 0)
            {
                return aux->func;
            }
        }
        aux = aux->next;
    }
    return NULL;
}

varDecl *find_var_in_function(Tree *head)
{
    table_elem *aux = symbols_table;

    while (aux != NULL)
    {
        if (aux->func)
        {
            varDecl *aux2 = aux->func->vars;

            while (aux2 != NULL)
            {
                if (strcmp(head->value, aux2->value) == 0 && (head->line > aux2->line))
                {
                    return aux2;
                }
                aux2 = aux2->next;
            }
        }
        aux = aux->next;
    }
    return NULL;
}

int check_params(Tree *call, funcDecl *func)
{
    Tree *aux = call->child->next;
    int i = 0;
    int j = 0;
    int isError = 0;

    while (aux != NULL)
    {
        anoted_tree(aux);

        varDecl *aux2 = func->vars;

        if (aux2->isParam == 0)
        {
            return 0;
        }

        j = 0;
        while (aux2 != NULL)
        {
            if (aux2->isParam == 1)
            {
                if (aux->print == NULL || (strcmp(aux->print, aux2->type) != 0 && i == j))
                {
                    isError = 1;
                }
            }
            j++;
            aux2 = aux2->next;
        }
        aux = aux->next;
        i++;
    }

    return isError;
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
        while (aux != NULL)
        {
            if (aux->func)
            {
                if (strcmp(aux->func->value, string) == 0)
                {
                    return 1;
                }
            }
            else if (aux->var)
            {
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

char *string_params_func(varDecl *vars_params)
{
    char *newString = malloc(sizeof(char) * MAX_STRING);
    varDecl *aux = vars_params;

    if (vars_params == NULL)
    {
        return NULL;
    }

    while (aux != NULL)
    {
        if (aux->isParam == 1)
        {
            strcat(newString, aux->type);
            if (aux->next != NULL && aux->next->isParam == 1)
            {
                strcat(newString, ",");
            }
        }
        aux = aux->next;
    }
    return newString;
}

char *prepare_to_print_error_params(Tree *node, int posicion)
{
    char *newString = malloc(sizeof(char) * MAX_STRING);
    Tree *aux = node->child->next;

    if (aux == NULL)
    {
        return NULL;
    }

    while (aux != NULL)
    {
        if (aux->print == NULL)
        {
            strcat(newString, "none");
        }
        else
        {
            strcat(newString, aux->print);
        }
        if (aux->next != NULL)
        {
            strcat(newString, ",");
        }
        aux = aux->next;
    }
    return newString;
}

int handle_semantic_errors(int line, int column, char *symbol, char *value, char *value2)
{
    semantic_errors = 1;
    if (value == NULL && value2 == NULL)
    {
        printf("Line %d, column %d: Operator %s cannot be applied to types undef, undef\n", line, column, symbol);
        return 1;
    }

    else if (value == NULL)
    {
        printf("Line %d, column %d: Operator %s cannot be applied to types undef, %s\n", line, column, symbol, value2);
        return 1;
    }

    else if (value2 == NULL)
    {
        printf("Line %d, column %d: Operator %s cannot be applied to types %s, undef\n", line, column, symbol, value);
        return 1;
    }

    else if (value != NULL && value2 != NULL)
    {
        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n", line, column, symbol, value, value2);
        return 1;
    }
    return 0;
}

char *clear_string_to_error(char *string)
{
    char *newString = malloc(sizeof(char) * MAX_STRING);
    strcpy(newString, string);

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ')' && string[i] == '(')
        {
            newString[i] = 'a';
        }
    }

    // printf("%s----------a\n", newString);

    return newString;
}