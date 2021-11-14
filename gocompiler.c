#include "gocompiler.h"

Tree *head = NULL;

Tree *addNode(char *token, char *value)
{

    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    newnode->token = token;
    newnode->value = value;
    newnode->next = NULL;
    head = newnode;

    return 0;
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
            printf("%s\n", proximo->value);
            proximo = proximo->next;
        }
    }
}
