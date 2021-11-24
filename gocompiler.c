#include "gocompiler.h"

Tree *createNode(char *token, char *value)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    newnode->token = token;
    newnode->value = value;

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
    Tree *funcParams = add1child(createNode("FuncParams", NULL), params);
    Tree *funcHeader = addchild(createNode("FuncHeader", NULL), id, addbro(type, funcParams));

    return addchild(createNode("FuncDecl", NULL), funcHeader, funcBody);
}

Tree *createListId(Tree *id, Tree *listIds, Tree *type)
{
    Tree *varDecl = createNode("VarDecl", NULL);
    add1child(varDecl, type);
    add1child(varDecl, id);

    if (listIds != NULL)
    {
        Tree *newId = listIds;
        Tree *varDecls[100];
        Tree *ids[100];
        int i = 0;
        int k = 0;

        //puts all Ids inside array
        while (newId != NULL)
        {
            ids[k] = newId;
            newId = newId->next;
            k++;
        }

        newId = listIds;
        Tree *aux;

        //destroys bro connections between Ids
        if (newId->next != NULL)
        {
            while (newId != NULL)
            {
                aux = newId->next;
                newId->next = NULL;
                newId = aux;
            }
        }

        Tree *auxType;

        //creates a new VarDecl node for each Id received from the IdOpt
        for (int n = 0; n < k; n++)
        { //iterates ids array
            varDecls[n] = createNode("VarDecl", NULL);
            auxType = createNode(type->token, NULL);
            add1child(varDecls[n], auxType);
            add1child(varDecls[n], ids[n]);
            i++;
        }

        if (i >= 1)
            addbro(varDecl, varDecls[0]);

        for (int j = 0; j + 1 < i; j++)
        {
            addbro(varDecls[j], varDecls[j + 1]);
        }
    }

    return varDecl;
}

Tree *cicleIf(Tree *condicions, Tree *content, Tree *contentElse)
{
    Tree *auxIf = NULL;
    if (!contentElse)
    {
        auxIf = addbro(addchild(createNode("Block", NULL), content, NULL), createNode("Block", NULL));
        return addchild(createNode("If", NULL), condicions, auxIf);
    }
    else
    {
        return add3child(createNode("If", NULL), condicions, add1child(createNode("Block", NULL), content), add1child(createNode("Block", NULL), contentElse));
    }
}

Tree *cicleFor(Tree *condicions, Tree *content)
{
    if (!condicions)
    {
        return add1child(createNode("For", NULL), add1child(createNode("Block", NULL), content));
    }
    else
    {
        return addchild(createNode("For", NULL), condicions, add1child(createNode("Block", NULL), content));
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
