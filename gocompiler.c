#include "gocompiler.h"

Tree *createNode(char *token, char *value)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    newnode->token = token;
    newnode->value = value;

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

Tree *add3child(Tree *parent, Tree *value1, Tree *value2, Tree *value3)
{
    parent->child = value1;
    value1->child = value2;

    if (value2 != NULL)
    {
        value2->next = value3;
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

Tree *createListId(Tree *listIds, Tree *type, int check)
{
    Tree *auxVarDecl = NULL;

    if (check == 1)
    {
        while (listIds->next != NULL)
        {
            auxVarDecl = addbro(auxVarDecl, addchild(createNode("VarDecl", NULL), type, listIds));
            listIds = listIds->next;
        }
    }
    else
    {
        while (listIds->next != NULL)
        {
            auxVarDecl = addchild(createNode("Call", NULL), listIds, NULL);
            listIds = listIds->next;
        }
    }

    return auxVarDecl;
}

Tree *cicleIf(Tree *condicions, Tree *content, Tree *contentElse)
{
    // Tree *blockElse = NULL;

    // Tree *block = addbro(condicions, addchild(createNode("Block", NULL), content, NULL));

    if (!contentElse)
    {
        addchild(createNode("If", NULL), condicions, addchild(createNode("Block", NULL), content, createNode("Block", NULL)));
    }
    else
    {

        add3child(createNode("If", NULL), condicions, addchild(createNode("Block", NULL), content, NULL), addchild(createNode("Block", NULL), contentElse, NULL));
    }
}
Tree *cicleFor(Tree *condicions, Tree *content)
{
    if (!condicions)
    {
        return addchild(createNode("For", NULL), addchild(createNode("Block", NULL), content, NULL), NULL);
    }
    else
    {
        return addchild(createNode("For", NULL), condicions, addchild(createNode("Block", NULL), content, NULL));
    }
}
