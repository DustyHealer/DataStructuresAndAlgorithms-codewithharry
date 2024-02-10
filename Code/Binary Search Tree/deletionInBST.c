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

struct node *inOrderPredessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Search the node
// Delete the node
struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Search for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // Deletion strategy when the node is found
    else
    {
        iPre = inOrderPredessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node to left and right node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    inorderTraversal(p);
    printf("\n");
    deleteNode(p, 3);
    inorderTraversal(p);
    printf("\n");
    deleteNode(p, 6);
    inorderTraversal(p);
    printf("\n");
    return 0;
}