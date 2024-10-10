#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
        return getNewNode(val);

    if (root->key < val)
        root->right = insert(root->right, val);

    else if (root->key > val)
        root->left = insert(root->left, val);

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void ElementsInRange(struct node *root, int lower, int higher)
{
    if (root == NULL)
        return;
    if(root->key > lower){
        ElementsInRange(root->left,lower,higher);
    }
    if(root->key >= lower && root->key <= higher){
    printf("%d ",root->key);
    }
    if(root->key < higher){
        ElementsInRange(root->right,lower,higher);
    }
   
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 33);
    root = insert(root, 19);
    root = insert(root, 49);
    root = insert(root, 5);
    root = insert(root, 27);
    root = insert(root, 43);
    root = insert(root, 54);
    root = insert(root, 1);
    root = insert(root, 12);
    root = insert(root, 29);
    root = insert(root, 45);
    root = insert(root, 59);

    printf("Enter M(lower value):");
    int lower;
    scanf("%d", &lower);
    printf("Enter N(higher value):");
    int higher;
    scanf("%d", &higher);
    printf("Elements in b/w %d and %d:\n", lower,higher);
    ElementsInRange(root, lower, higher);
    // inorder(root);

    return 0;
}