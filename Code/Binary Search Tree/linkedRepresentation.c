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

int main()
{
    /*
    // Construct the root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Construct the second node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Construct the third node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */

    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking the root node to left and right node
    p->left = p1;
    p->right = p2;
    return 0;
}