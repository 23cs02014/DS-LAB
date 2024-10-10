#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Creating Tree Node
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int PathForSum(struct Node * root , int k){
    if(root == NULL){
        return 0;
    }
    

    return 0;
}

int main()
{
    struct Node *root = createNode(33);
    root->left = createNode(9);
    root->left->left = createNode(5);
    root->left->left->left = createNode(1);
    root->left->left->right = createNode(12);
    root->left->right = createNode(7);
    root->left->right->right = createNode(6);
    root->right = createNode(19);
    root->right->right = createNode(4);
    root->right->right->right = createNode(9);
    root->right->left = createNode(23);
    root->right->left->right = createNode(8);

    int k;
    printf("Enter the sum:");
    scanf("%d", &k);
    if(!PathForSum(root,k)){
        printf("No path found");
    }

    return 0;
}
