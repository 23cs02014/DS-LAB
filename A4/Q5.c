#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
};

// Creating Tree Node
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
int countChildren(struct Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
    {
        struct Node *tmp = root->firstChild;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->nextSibling;
        }
        return count;
    }
    else
    {
        int x = countChildren(root->firstChild, key);
        if (x != 0)
            return x;
        else
            return countChildren(root->nextSibling, key);
    }
}
int main()
{
    struct Node *root = createNode(33);
    root->firstChild = createNode(9);
    root->firstChild->firstChild = createNode(5);
    root->firstChild->firstChild->nextSibling = createNode(12);
    root->firstChild->firstChild->nextSibling->nextSibling = createNode(17);

    root->firstChild->nextSibling = createNode(7);

    root->firstChild->nextSibling->nextSibling = createNode(19);
    root->firstChild->nextSibling->nextSibling->firstChild = createNode(2);
    root->firstChild->nextSibling->nextSibling->firstChild->nextSibling = createNode(4);

    printf("Enter the node to count children:");
    int x;
    scanf(" %d", &x);
    printf("Number of children of %d is %d", x, countChildren(root, x));
    return 0;
}