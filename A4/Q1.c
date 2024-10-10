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
int sum = 0;
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    sum += root->data;
    inorder(root->right);
}

int SumOfTree(struct Node *root)
{
    inorder(root);
    return sum;
}
int main()
{
    struct Node *root = createNode(33);
    root->left = createNode(99);
    root->left->left = createNode(5);
    root->right = createNode(39);
    root->right->right = createNode(81);
    root->right->left = createNode(10);
    printf("SUM = %d", SumOfTree(root));

    return 0;
}