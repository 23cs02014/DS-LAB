#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
};

void AddatEnd(struct DLL **h, int newdata)
{
    struct DLL *new = (struct DLL *)malloc(sizeof(struct DLL));
    struct DLL *last = *h;
    new->data = newdata;
    new->next = NULL;
    if (*h == NULL)
    {
        *h = new;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
    new->prev = last;
}

void printDLL(struct DLL *h)
{
    while (h != NULL)
    {
        printf(" %d", h->data);
        h = h->next;
    }
    printf("\n");
}

void DeleteNthNode(struct DLL **h, int nth)
{
    struct DLL *tmp = *h;
    if (tmp == NULL)
    {
        printf("Error: List is empty\n");
        return;
    }
    if (nth == 1)
    {
        *h = tmp->next;
        if (*h != NULL)
        {
            (*h)->prev = NULL;
        }
        free(tmp);
        return;
    }
    for (int i = 0; i < nth - 1; i++)
    {
        if (tmp == NULL)
        {
            printf("Error: nth > number of elements in DLL\n");
            return;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("Error: nth > number of elements in DLL\n");
        return;
    }
    if (tmp->next != NULL)
    {
        tmp->next->prev = tmp->prev;
    }
    tmp->prev->next = tmp->next;
    free(tmp);
}

int main()
{
    struct DLL *head = NULL;
    printf("Nodes in DLL: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        int x;
        scanf("%d", &x);
        AddatEnd(&head, x);
    }
    printf("Nth element to remove: ");
    int a;
    scanf("%d", &a);
    DeleteNthNode(&head, a);
    printf("Updated DLL: ");
    printDLL(head);

    return 0;
}