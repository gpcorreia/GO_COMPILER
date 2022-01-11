#include "gocompiler.h"
#include "y.tab.h"

Tree *createNode(char *token, char *value, char *print) //,int line,int
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    newnode->token = token;
    newnode->value = value;
    newnode->print = print;
    newnode->line = yylval.token.line;
    newnode->column = yylval.token.column;
    return newnode;
}

Tree *add1child(Tree *parent, Tree *child)
{
    parent->child = child;
    return parent;
}

Tree *addchild(Tree *parent, Tree *value1, Tree *value2)
{
    parent->child = value1;

    if (value1 != NULL)
    {
        value1->next = value2;
    }

    return parent;
}

Tree *addbro(Tree *head, Tree *bro)
{

    Tree *ptr = head;

    if (head == NULL)
    {
        return bro;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = bro;

    return head;
}

Tree *createFuncDecl(Tree *id, Tree *params, Tree *type, Tree *funcBody)
{
    Tree *funcParams = add1child(createNode("FuncParams", NULL, NULL), params);
    Tree *funcHeader = addchild(createNode("FuncHeader", NULL, NULL), id, addbro(type, funcParams));

    return addchild(createNode("FuncDecl", NULL, NULL), funcHeader, funcBody);
}

Tree *createListId(Tree *listIds, Tree *type)
{
    if (listIds != NULL)
    {
        Tree *varDecl = listIds;
        Tree *aux;
        Tree *varDecls[100];
        int i = 0;
        int k = 0;

        Tree *auxtype;

        while (varDecl != NULL)
        {
            varDecls[k] = createNode("VarDecl", NULL, NULL);
            auxtype = createNode(type->token, NULL, NULL);
            addchild(varDecls[k], auxtype, varDecl);
            k++;
            i++;
            varDecl = varDecl->next;
        }

        Tree *varDecl2 = listIds;

        if (varDecl2->next != NULL)
        {
            while (varDecl2 != NULL)
            {
                aux = varDecl2->next;
                varDecl2->next = NULL;
                varDecl2 = aux;
            }
        }

        varDecl = varDecls[0];

        for (int j = 0; j + 1 < i; j++)
        {
            addbro(varDecls[j], varDecls[j + 1]);
        }

        return varDecl;
    }
    return NULL;
}

Tree *cicleIf(Tree *condicions, Tree *content, Tree *contentElse)
{
    Tree *auxIf = NULL;
    Tree *auxIfCondicions = NULL;
    if (!contentElse)
    {
        auxIf = addbro(add1child(createNode("Block", NULL, NULL), content), createNode("Block", NULL, NULL));

        return addchild(createNode("If", NULL, NULL), condicions, auxIf);
    }
    else
    {
        auxIf = addbro(add1child(createNode("Block", NULL, NULL), content), add1child(createNode("Block", NULL, NULL), contentElse));
        auxIfCondicions = addbro(condicions, auxIf);
        return add1child(createNode("If", NULL, NULL), auxIfCondicions);
    }
}

Tree *cicleFor(Tree *condicions, Tree *content)
{
    if (!condicions)
    {
        return add1child(createNode("For", NULL, NULL), add1child(createNode("Block", NULL, NULL), content));
    }
    else
    {
        return addchild(createNode("For", NULL, NULL), condicions, add1child(createNode("Block", NULL, NULL), content));
    }
}

void showList(Tree *head, int point2print)
{

    if (head == NULL)
    {
        return;
    }

    for (int i = 0; i < point2print; i++)
    {
        printf(".");
    }

    if (!head->value)
    {
        if (head->print)
            printf("%s - %s\n", head->token, head->print);
        else
            printf("%s\n", head->token);
    }
    else
    {
        if (strcmp(head->token, "StrLit") == 0)
        {
            printf("%s(\"%s\")\n", head->token, head->value);
        }
        else
        {
            if (head->print != NULL)
                printf("%s(%s) - %s\n", head->token, head->value, head->print);

            else
                printf("%s(%s)\n", head->token, head->value);
        }
    }

    if (head->child)
    {
        showList(head->child, point2print + 2);
    }
    if (head->next)
    {
        showList(head->next, point2print);
    }
}
