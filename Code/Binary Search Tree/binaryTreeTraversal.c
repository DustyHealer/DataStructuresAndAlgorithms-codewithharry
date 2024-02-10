#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory dynamically
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Root -> Left -> Right
void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    // Should print 4 1 5 2 6
}

// Left -> Right -> Root
void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
    // Should print 5 2 1 6 4
}

// Left -> Root -> Right
void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
    // Should print 5 1 2 4 6
}

int main()
{
    // Create nodes
    // struct node *p = createNode(4);
    // struct node *p1 = createNode(1);
    // struct node *p2 = createNode(6);
    // struct node *p3 = createNode(5);
    // struct node *p4 = createNode(2);

    struct node *p = createNode(7);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(0);
    struct node *p4 = createNode(4);

    // Linking the root node to left and right node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("Pre-Order Traversal: ");
    preorderTraversal(p);
    printf("\nPost-Order Traversal: ");
    postorderTraversal(p);
    printf("\nIn-Order Traversal: ");
    inorderTraversal(p);

    return 0;
}