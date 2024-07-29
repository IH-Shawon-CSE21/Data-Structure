#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
} *root = NULL;
typedef struct Node node;

node *newNode(int item)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;

    return new;
}
node *insert()
{
    int x;
    scanf("%d", &x);
    node *newRoot = newNode(x);

    if (x == 0)
    {
        return 0;
    }

    printf("Enter left child of %d : ", x);
    newRoot->left = insert();

    printf("Enter right child of %d : ", x);
    newRoot->right = insert();

    return newRoot;
}
void traverse_Pre(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    traverse_Pre(root->left);
    traverse_Pre(root->right);
}
int main()
{
    printf("\nEnter the root : ");
    root = insert();

    printf("The Preorder list is : ");
    traverse_Pre(root);

    return 0;
}