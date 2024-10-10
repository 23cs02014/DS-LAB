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

struct LNode
{
    int data;           
    struct LNode *next; 
};
void insertAtEnd(struct LNode **head_ref, int new_data)
{
    struct

        LNode *new_node = (struct LNode *)malloc(sizeof(struct LNode));
    struct LNode *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

struct LNode *x1 = NULL;
struct LNode *x2 = NULL;
void inorder1(struct Node *root)
{
    if (root == NULL)
        return;
    inorder1(root->left);
    insertAtEnd(&x1, root->data);
    inorder1(root->right);
}
void inorder2(struct Node *root)
{
    if (root == NULL)
        return;
    inorder2(root->right);
    insertAtEnd(&x2, root->data);
    inorder2(root->left);
}
void preOrderTraversal(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

int f = 0;
void checkMirrorImage(struct Node *n1, struct Node *n2)
{
    if (n1 == NULL)
        return;
    if (n2 == NULL)
        return;
    inorder1(n1);
    inorder2(n2);
    while (x1 != NULL && x2 != NULL)
    {
        if (x1->data != x2->data)
        {
            f = 1;
            break;
        }
        x1 = x1->next;
        x2 = x2->next;
    }
}
int main()
{
    struct Node *n1 = NULL;
    struct Node *n2 = NULL;
    printf("enter number of elements:");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter %d level-order value for tree1:",i+1);
        int x;
        scanf("%d", &x);
        n1 = insert(n1, x);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("enter %d level-order value for tree2:",i+1);
        int x;
        scanf("%d", &x);
        n2 = insert(n2, x);
    }
    printf("Preorder for tree1:");
    preOrderTraversal(n1);
    printf("\nPreorder for tree2:");
    preOrderTraversal(n2);
    checkMirrorImage(n1, n2);
    if (f)
    {
        printf("\nNo, tree1 and tree2 are not mirror images");
        return 0;
    }

    printf("\nYes, tree1 and tree2 are mirror images");

    return 0;
}