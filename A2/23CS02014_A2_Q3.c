#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // Holds the element in the node
    struct Node *next; // Holds the Pointer to the next node
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{

    // Allocate memory for a new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    // insert the elements
    new_node->data = new_data;
    new_node->next = (*head_ref);
    // Move head to new node
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
struct Node *IntersectionList(struct Node *headm, struct Node *headn)
{
    struct Node *intersection = NULL;
    struct Node *tmpm = headm;
    struct Node *tmpn = headn;
    while (tmpm != NULL)
    {
        while (tmpn != NULL)
        {
            if (tmpm->data == tmpn->data)
            {
                insertAtBeginning(&intersection, tmpm->data);
            }
            tmpn = tmpn->next;
        }
        tmpn = headn;
        tmpm = tmpm->next;
    }
    return intersection;
}
int main()
{
    struct Node *headm = NULL;
    struct Node *headn = NULL;
    printf("number of nodes m:");
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        printf("data for node %d:", i + 1);
        int x;
        scanf("%d", &x);
        insertAtBeginning(&headm, x);
    }
    printf("number of nodes n:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("data for node %d:", i + 1);
        int x;
        scanf("%d", &x);
        insertAtBeginning(&headn, x);
    }
    printf("Intersection:");
    printList(IntersectionList(headm, headn));
}