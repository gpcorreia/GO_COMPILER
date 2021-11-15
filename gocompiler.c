#include "gocompiler.h"

Tree *addNode(char *token, char *value)
{
    Tree *newnode = (Tree *)malloc(sizeof(Tree));

    strcpy(newnode->token, token);
    strcpy(newnode->value, value);
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
            printf("No: %s\n", proximo->token);
            proximo = proximo->next;
        }
    }
}
