#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char arr[], int start, int end, char value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node *buildTree(char inorder[], char postorder[], int inStart, int inEnd, int *postIndex)
{
    if (inStart > inEnd)
        return NULL;
    char curr = postorder[*postIndex];
    (*postIndex)--;
    struct Node *node = createNode(curr);
    if (inStart == inEnd)
        return node;
    int inIndex = search(inorder, inStart, inEnd, curr);
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return node;
}
void preOrderTraversal(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%c ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

int main()
{
    char inorder[100], postorder[100];

    printf("Enter Inorder: ");
    scanf("%s", inorder);
    printf("Enter PostOrder: ");
    scanf("%s", postorder);

    int length = strlen(inorder);
    int postIndex = length - 1;

    struct Node *root = buildTree(inorder, postorder, 0, length - 1, &postIndex);

    printf("Preorder: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}