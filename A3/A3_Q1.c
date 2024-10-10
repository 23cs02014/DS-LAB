#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;          
    struct Node *next; 
};
struct Node *head = NULL;
void insertAtEnd(int val){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    if(head==NULL){
        head = newnode;
        head->next = newnode;
        return;
    }
    struct Node *last = head;
    while(last->next != head){
        last = last->next;
    }
    last->next = newnode;
    newnode->next = head;
    return;
}
void printList(){
    if(head==NULL){
        printf("NULL");
        return;
    }
    struct Node* tmp = head;
    printf("%d ",tmp->data);
    tmp = tmp->next;
    while(tmp != head){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    return;
}
void SearchInCLL(int val){
    int count = 1;
    if(head==NULL){
        printf("NULL");
        return;
    }
    struct Node* tmp = head;
    _Bool b = 0;
    // printf("%d ",tmp->data);
    printf("Posn:");
    if(tmp->data==val){
        printf("1 ");
        b = 1;
    }
    tmp = tmp->next;
    while(tmp != head){
        count++;
        if(tmp->data == val){
        printf("%d ",count);
        }
        tmp = tmp->next;
        b = 1;
    }
    if(b){
        printf("Not in list");
    }
printf("\n");
    return;
}
int main()
{
    printf("Enter no of nodes:");
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        printf("enter %d data:",i+1);
        int x;
        scanf("%d",&x);
        insertAtEnd(x);
    }
   printf("values in CLL:");
    printList();
    printf("Element to find:");
    scanf("%d",&n);
    SearchInCLL(n);
}