#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;
struct node * front1 = NULL, *rear1 = NULL;
void enqueue(int val,struct node * front, struct node * rear)
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

int dequeue(struct node * front, struct node * rear)
{
    // used to free the first node after dequeue
    struct node *temp;

    if (front == NULL)
        printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        // take backup
        temp = front;
        int x = temp->data;
        // make the front node points to the next node
        // logically removing the front element
        front = front->next;

        // if front == NULL, set rear = NULL
        if (front == NULL)
            rear = NULL;

        // free the first node
        free(temp);
        return x;
    }
}

void printList(struct node * front)
{
    struct node *temp = front;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
printf("\n");
}
void enqueueElements()
{
    printf("Enter number of elements to be enqueued:");
    int n;
    scanf("%d", &n);
    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        int y;
        scanf("%d", &y);
        enqueue(y,front,rear);
    }
    printf("created queue of size %d: ", n);
    printList(front);
}
int size(){
    struct node * tmp = front;
    int count = 0;
    while(tmp != rear){
        tmp = tmp->next;
        count++;
    }
    return count+1;
}
void dequeueElement()
{
    printf("Removed element = %d\n", dequeue(front,rear));
    printf("Current size = %d\n",size());
    printf("Current elements:");
    printList(front);

}
void removeVal(int key){
    struct node* tmp = front;
    while(tmp!= NULL){
        if(dequeue(front,rear) != key){
            enqueue(tmp->data,front1,rear1);
        }
    }
    tmp = front1;
    while(tmp!=NULL){
        enqueue(dequeue(front1,rear1),front,rear);
    }
}
void removeMaxMin(){
    int max = INT_MIN;
    int min = INT_MAX;
    struct node* tmp = front;
    while(tmp != NULL){
        if(tmp->data > max){
            max = tmp->data;
        }
        if(tmp->data < min){
            min = tmp->data;
        }
        tmp = tmp->next;
    }

    printf("%d %d",max,min);
    // removeVal(max);
    // printList();

}

int main()
{
    while (1)
    {
        printf("Enter your choice (1 for Enqueue, 2 for Dequeue, 3 for Remove MaxMin, 4 for Exit) :");
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            enqueueElements();
        }
        else if (x == 2)
        {
            dequeueElement();
        }
        else if(x==3){
            removeMaxMin();
        }
        else
        {
            break;
        }
    }
    printf("\nQueue Operations Completed, Bye! ...............");
    return 0;
}