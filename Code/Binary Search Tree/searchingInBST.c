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

int isBinarySearchTree(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBinarySearchTree(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBinarySearchTree(root->right);
    }
    else
    {
        return 1;
    }
}

// Search using iteration
struct node *iterativeSearch(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;
}

// Search using Recursion
struct node *search(struct node *root, int val)
{
    if (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (val > root->data)
        {
            return search(root->right, val);
        }
        else
        {
            return search(root->left, val);
        }
    }
    else
    {
        return NULL;
    }
}

int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(5);

    // Linking the root node to left and right node
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // printf("\nIn-Order Traversal: ");
    // inorderTraversal(p);
    // printf("\nBinary Tree Or not: %d", isBinarySearchTree(p));
    int searchValue = 3;
    struct node *n1 = search(p, searchValue);
    if (n1 == NULL)
    {
        printf("Search Node %d is not present in the BST\n", searchValue);
    }
    else
    {
        printf("Search Node %d is present in the BST\n", n1->data);
    }

    searchValue = 6;
    struct node *n2 = iterativeSearch(p, searchValue);

    if (n2 == NULL)
    {
        printf("Search Node %d is not present in the BST\n", searchValue);
    }
    else
    {
        printf("Search Node %d is present in the BST\n", n2->data);
    }
    return 0;
}