#include <stdio.h>
#include <stdlib.h>
// Define a node
struct Node
{
    int data;          // Holds the element in the node
    struct Node *next; // Holds the Pointer to the next node
};

// Insert at the end of the linked list

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

int ComputeAverage(struct Node *h)
{
    int avg = 0, count = 0;
    while (h != NULL)
    {
        avg += h->data;
        count++;
        h = h->next;
    }
    avg /= count;
}

int main()
{
    struct Node *head = NULL;
    printf("number of nodes:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("data for node %d:", i + 1);
        int x;
        scanf("%d", &x);
        insertAtEnd(&head, x);
    }
    printf("\navg=%d", ComputeAverage(head));
}