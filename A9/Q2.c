#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int d){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct Node *temp = queue[front++];
        if (temp->left == NULL)
        {
            temp->left = createNode(key);
            break;
        }
        else
        {
            queue[rear++] = temp->left;
        }
        if (temp->right == NULL)
        {
            temp->right = createNode(key);
            break;
        }
        else
        {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int n,int a[n]){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
}
void inOrderTraversal(struct Node *node){
    if (node == NULL) return;
    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
}
_Bool isMinHeap(struct Node* root){
    if(root->left != NULL && root->right!= NULL){
        if(root->left->data > root->data && root->right->data > root->data){
            return isMinHeap(root->left) && isMinHeap(root->right);
        }
            return 0;
    }
    else if(root->left == NULL && root->right!= NULL){
        if(root->right->data > root->data){
            return isMinHeap(root->right);
        }
            return 0;
    }
    else if(root->right == NULL && root->left!= NULL){
        if(root->left->data > root->data){
            return isMinHeap(root->left);
        }
            return 0;
    }
    else if(root->right == NULL && root->left== NULL){
        return 1;
    }


}
struct Node *node = NULL;
int main(){
    printf("Enter the number of elements in the tree:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for(int i = 0 ; i < n ; i++){
        int x;
        scanf(" %d",&x);
       node = insert(node,x);
    }
    //inOrderTraversal(node);
    if(isMinHeap(node)){
        printf("is min heap");
        return 0;
    }
    printf("is not min heap");
   
}