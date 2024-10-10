#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    // if it is the first node
    if (front == NULL && rear == NULL)
        // make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        // add newnode in rear->next
        rear->next = newNode;

        // make the new node as the rear node
        rear = newNode;
    }
}

void dequeue()
{
    // used to free the first node after dequeue
    struct node *temp;

    if (front == NULL)
        printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        // take backup
        temp = front;

        // make the front node points to the next node
        // logically removing the front element
        front = front->next;

        // if front == NULL, set rear = NULL
        if (front == NULL)
            rear = NULL;

        // free the first node
        free(temp);
    }
}

void printList()
{
    struct node *temp = front;

    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("no of items in queue:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("insert into %d queue:", i + 1);
        int x;
        scanf("%d", &x);
        enqueue(x);
    }
    printList();
    printf("posn of element to be deleted:");
    int n1;
    scanf("%d", &n1);
    // printf("n1=%d",n1);
    struct node *tmpf = front;
    for (int i = 0; i < n1-1; i++)
    {
        if (tmpf != NULL)
            tmpf = tmpf->next;
    }

    if (tmpf == rear->next)
    {
        printf("Invalid posn");

    }
    else{
    for (int i = 0; i < n1; i++)
    {
        dequeue();
    }
    printList();
    }
    return 0;
}