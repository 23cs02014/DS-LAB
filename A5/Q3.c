#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left, *right;
};
struct Node *newNode(char data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

struct Node *buildTree(char postfix[])
{
    struct Node *stack[100];
    int top = -1;

    // Traverse
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];

        // If operand, push to stack
        if (isOperand(c))
        {
            stack[++top] = newNode(c);
        }
        // If operator, pop two nodes, make them children, and push the result back
        else if (isOperator(c))
        {
            struct Node *node = newNode(c);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }
    return stack[top];
}
void printInfix(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left && root->right)
            printf("(");
        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);
        if (root->left && root->right)
            printf(")");
    }
}

int main()
{
   printf("Enter postfix:");
    char postfix[] = "";
   scanf(" %s",&postfix);

    struct Node *root = buildTree(postfix);
    printf("Infix expression: ");
    printInfix(root);
    printf("\n");

    return 0;
}