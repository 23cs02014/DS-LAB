#include <stdio.h>
#include <stdlib.h>

struct AVLTreeNode
{
   int data;
   struct AVLTreeNode *leftChild;
   struct AVLTreeNode *rightChild;
   int height;
};

int height(struct AVLTreeNode *N)
{
   if (N == NULL)
      return 0;
   return N->height;
}

int max(int a, int b)
{
   return (a > b) ? a : b;
}

struct AVLTreeNode *newAVLTreeNode(int data)
{
   struct AVLTreeNode *node = (struct AVLTreeNode *)malloc(sizeof(struct AVLTreeNode));
   node->data = data;
   node->leftChild = NULL;
   node->rightChild = NULL;
   node->height = 1;
   return (node);
}

struct AVLTreeNode *rightRotate(struct AVLTreeNode *y)
{
   struct AVLTreeNode *x = y->leftChild;
   struct AVLTreeNode *T2 = x->rightChild;
   x->rightChild = y;
   y->leftChild = T2;
   y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
   x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
   return x;
}

struct AVLTreeNode *leftRotate(struct AVLTreeNode *x)
{
   struct AVLTreeNode *y = x->rightChild;
   struct AVLTreeNode *T2 = y->leftChild;
   y->leftChild = x;
   x->rightChild = T2;
   x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
   y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
   return y;
}


int getBalance(struct AVLTreeNode *N)
{
   if (N == NULL)
      return 0;
   return height(N->leftChild) - height(N->rightChild);
}
struct AVLTreeNode *minValueNode(struct AVLTreeNode* node) {
    struct AVLTreeNode* current = node;
    while (current->leftChild != NULL)
        current = current->leftChild;
    return current;
}
struct AVLTreeNode *insertAVLTreeNode(struct AVLTreeNode *node, int data)
{
   if (node == NULL)
      return (newAVLTreeNode(data));
   if (data < node->data)
      node->leftChild = insertAVLTreeNode(node->leftChild, data);
   else if (data > node->data)
      node->rightChild = insertAVLTreeNode(node->rightChild, data);
   else
      return node;
   node->height = 1 + max(height(node->leftChild),
                          height(node->rightChild));
   int balance = getBalance(node);
   if (balance > 1 && data < node->leftChild->data)
      return rightRotate(node);
   if (balance < -1 && data > node->rightChild->data)
      return leftRotate(node);
   if (balance > 1 && data > node->leftChild->data)
   {
      node->leftChild = leftRotate(node->leftChild);
      return rightRotate(node);
   }
   if (balance < -1 && data < node->rightChild->data)
   {
      node->rightChild = rightRotate(node->rightChild);
      return leftRotate(node);
   }
   return node;
}
void printTree(struct AVLTreeNode *root)
{
   if (root != NULL)
   {
      printTree(root->leftChild);
      printf("%d ", root->data);
      printTree(root->rightChild);
   }
}


int main()
{
   struct AVLTreeNode *root = NULL;
   int n, x;
   printf("Enter the number of elements: ");
   scanf("%d", &n);
   printf("Enter the elements: ");
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &x);
      root = insertAVLTreeNode(root, x);
   }
   printf("AVL Tree: ");
   printTree(root); // inorder traversal
   printf("\nNode to remove:");
   scanf("%d", &n);
   removeNode(root, n);
   printf("AVL Tree after deletion: ");
   printTree(root);

   return 0;
}