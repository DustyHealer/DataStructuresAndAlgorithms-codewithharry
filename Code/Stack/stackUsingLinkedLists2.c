#include <stdio.h>
#include <stdlib.h>

struct Node *top = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d =>", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return;
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int x)
{
    if (isFull())
    {
        printf("Stack overflow, unable to push %d\n", x);
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow, unable to pop element\n");
    }
    else
    {
        int x = top->data;
        struct Node *n = top;
        top = top->next;
        free(n);
        return x;
    }
    return 0;
}

int peek(int index)
{
    if (isEmpty())
    {
        printf("Stack is empty, cannot peek\n");
    }
    else
    {
        struct Node *n = top;
        int i = 1;
        while (i < index && n != NULL)
        {
            n = n->next;
            i++;
        }
        if (n != NULL)
        {
            return n->data;
        }
    }
    return -1;
}

int StackTop()
{
    if (isEmpty())
    {
        printf("Stack is empty, cannot return top\n");
    }
    else
    {
        return top->data;
    }
}

int stackBottom()
{
    if (isEmpty())
    {
        printf("Stack is empty, cannot return bottom\n");
    }
    else
    {
        struct Node *n = top;
        while (n->next != NULL)
        {
            n = n->next;
        }
        return n->data;
    }
}

int main()
{
    traversal(top);
    push(78);
    push(7);
    push(8);
    traversal(top);
    printf("Stack Top: %d\n", StackTop());
    printf("Stack Bottom: %d\n", stackBottom());
    printf("Peeked element at index 2 is %d\n", peek(2));
    printf("Peeked element at index 3 is %d\n", peek(3));
    printf("Peeked element at index 4 is %d\n", peek(4));
    printf("Popped element is %d\n", pop());
    printf("Popped element is %d\n", pop());
    printf("Popped element is %d\n", pop());
    traversal(top);

    return 0;
}