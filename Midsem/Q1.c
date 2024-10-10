#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertAtEnd(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    if (head == NULL)
    {
        head = newnode;
        head->next = newnode;
        return;
    }
    struct Node *last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->next = head;
    return;
}
void printList()
{
    if (head == NULL)
    {
        printf("NULL");
        return;
    }
    struct Node *tmp = head;
    printf("%d ", tmp->data);
    tmp = tmp->next;
    while (tmp != head)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return;
}
struct Node *reversePairwise(struct Node *h)
{
    if (h == NULL)
    {
        return h;
    }
    struct Node* hold = h;
    struct Node* r = h->next;
    do{
    struct Node * tmp1 = h->next;
    struct Node * tmp2 = tmp1;
    while(tmp2->next != h){
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp1;
    h->next = tmp1->next;
    tmp1->next = h;
    h=h->next;
    }while(h->next != hold);
    return r;
}
int main()
{
    printf("Enter no of nodes:");
    int n;
    scanf("%d", &n);
    if(n%2){
        printf("Odd number");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("enter %d data: ", i + 1);
        int x;
        scanf("%d", &x);
        insertAtEnd(x);
    }
    printf("original:");
    printList();
    head = reversePairwise(head);
    printf("after pairwise reversal: ");
    printList();
}