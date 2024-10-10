#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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
}

void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void RemoveOddIndices(struct Node **head_ref)
{
    struct Node *current = *head_ref;
    struct Node *prev = NULL;
    int count = 1;

    while (current != NULL)
    {
        if (count % 2 == 1)
        {
            struct Node *temp = current;
            if (prev != NULL)
                prev->next = current->next;
            else
                *head_ref = current->next;
            current = current->next;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
        count++;
    }
}

int main()
{
    struct Node *head = NULL;
    printf("Number of nodes: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Data for node %d: ", i + 1);
        int x;
        scanf("%d", &x);
        insertAtEnd(&head, x);
    }

    printf("Original list: ");
    printList(head);

    RemoveOddIndices(&head);

    printf("\nList after removing elements with odd indices: ");
    printList(head);

    return 0;
}