#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stack
{
    int size;
    int top;
    struct Node *list;
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

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
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
    return top;
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow, unable to pop element\n");
    }
    else
    {
        int x = (*top)->data;
        struct Node *n = *top;
        *top = (*top)->next;
        free(n);
        return x;
    }
    return 0;
}

int peek(struct Node *top, int index)
{
    if (isEmpty(top))
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

int stackTop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Cannot return stack top, since stack is empty\n");
    }
    else
    {
        return top->data;
    }
}

int stackBottom(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Cannot return stack bottom, since stack is empty\n");
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
    struct Node *top = NULL;
    traversal(top);
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    traversal(top);
    printf("Stack Top: %d\n", stackTop(top));
    printf("Stack Bottom: %d\n", stackBottom(top));
    printf("Peek element at index 2: %d\n", peek(top, 2));
    printf("Peek element at index 3: %d\n", peek(top, 3));
    printf("Peek element at index 4: %d\n", peek(top, 4));
    printf("Popped element is %d\n", pop(&top));
    printf("Popped element is %d\n", pop(&top));
    printf("Popped element is %d\n", pop(&top));
    traversal(top);

    return 0;
}