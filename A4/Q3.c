#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void DeleteNodeWithRootedSubTree(struct Node *root, int key)
{
    if (root == NULL)
        return;
    if (root->left != NULL && root->left->data == key)
    {
        root->left = NULL;
        return;
    }
    else if (root->right != NULL && root->right->data == key)
    {
        root->right = NULL;
        return;
    }
    else
    {
        DeleteNodeWithRootedSubTree(root->left, key);
        DeleteNodeWithRootedSubTree(root->right, key);
    }
}
void preOrderTraversal(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
int main()
{
    struct Node *root = createNode(34);
    root->left = createNode(9);
    root->left->left = createNode(51);
    root->left->right = createNode(7);
    root->left->right->right = createNode(84);
    root->right = createNode(97);
    root->right->left = createNode(23);

    preOrderTraversal(root);
    printf("\nNode to be deleted:");
    int x;
    scanf("%d", &x);
    DeleteNodeWithRootedSubTree(root, x);
    preOrderTraversal(root);
    return 0;
}