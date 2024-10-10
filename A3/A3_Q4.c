// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};
struct node *head = NULL;

void push(char val)
{
    // create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    // make the new node points to the head node
    newNode->next = head;

    // make the new node as head node
    // so that head will always point the last inserted data
    head = newNode;
}

// remove data from the top of stack
void pop()
{
    // temp is used to free the head node
    struct node *temp;

    if (head == NULL)
        printf("Stack is Empty\n");
    else
    {
        // printf("Poped element = %c\n", head->data);

        // backup the head node
        temp = head;

        // make the head node points to the next node.
        // logically removing the node
        head = head->next;

        // free the poped element's memory
        free(temp);
    }
}

// print the linked list

void printList()
{
    struct node *temp = head;

    // iterate the entire linked list and print the data
    while (temp != NULL)
    {
        printf("%c->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

char peek()
{
    return (head->data);
}

// Driver program to test above functions
int main()
{

    char s[1000];
    printf("enter string:");
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i]);
        }
        else if ((s[i] == '}')&& (peek() == '{'))
        {
            pop();
        }
        else if (s[i] == ']' && peek() == '[')
        {
            pop();
        }
        else if (s[i] == ')' && peek() == '(')
        {
            pop();
        }
        else
        {
            printf("invalid input");
            return 0;
        }
        i++;
    }
    if (head == NULL)
    {
        printf("balanced");
        return 0;
    }
    printf("unbalanced");

    return 0;
}