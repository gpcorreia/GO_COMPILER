#include "gocompiler.h"

Tree *createNode(char *token, char *value)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    strcpy(newnode->token, token);
    strcpy(newnode->value, value);

    return newnode;
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
    Tree *last = head;

    if (head == NULL)
    {
        return bro;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = bro;

    return head;
}

Tree *createFuncDecl(Tree *id, Tree *params, Tree *type, Tree *funcBody)
{
    Tree *funcParams = addchild(createNode("FuncParams", NULL), params, NULL);
    Tree *funcHeader = addchild(createNode("FuncHeader", NULL), id, addbro(type, funcParams));

    return addchild(createNode("FuncDecl", NULL), funcHeader, funcBody);
}

void showList()
{
    Tree *proximo = head;
    if (head == NULL)
    {
        printf("Arvore Vazia\n");
    }
    else
    {
        while (proximo != NULL)
        {
            printf("No: %s\n", proximo->token);
            proximo = proximo->next;
        }
    }
}
