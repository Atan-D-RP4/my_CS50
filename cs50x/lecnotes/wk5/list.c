//Singly-Linked List that is preppended to

#include <stdio.h>
#include <stdlib.h>

typedef struct sllist
{
    int number;
    struct sllist *next;
}
sllnode;

int main(int argc, char* argv[])
{
    sllnode *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        sllnode *n = malloc(sizeof(sllnode));
        if (n == NULL)
        {
            return 1;
        }

        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    for (sllnode *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    for (sllnode *ptr = list, *next = ptr->next; ptr != NULL; ptr = next)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
}