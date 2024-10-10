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
    return;
}
void printDLL(struct DLL *h)
{
    while (h != NULL)
    {
        printf(" %d", h->data);
        h = h->next;
    }
    return;
}
int checkPallindrome(struct DLL **h)
{
    struct DLL *tmp1 = *h;
    struct DLL *tmp2 = *h;
    while (tmp2->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    // printf("\n:%d", tmp2->data);
    while (((tmp1->next) != NULL) && ((tmp2->prev) != NULL))
    {
        if ((tmp1->data) != (tmp2->data))
        {
            return 0;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->prev;
    }
    return 1;
}
int main()
{
    struct DLL *head = NULL;
    printf("Nodes in DLL:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter %d value:", i + 1);
        int x;
        scanf("%d", &x);
        AddatEnd(&head, x);
    }
    // printDLL(head);
    if (checkPallindrome(&head))
    {
        printf("is");
    }
    else
    {
        printf("isnt");
    }
}