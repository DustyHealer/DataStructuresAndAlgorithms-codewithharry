#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow, Cannot push %d into stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    return;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    { 
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int position) // In peek we start index from the top of the stack
{
    if (ptr->top - position + 1 < 0)
    {
        printf("Not a valid position in stack\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - position + 1];
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before push, Full: %d\n", isFull(sp));
    printf("Before push, Full: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 10); // Pushed 10 values
    push(sp, 11);
    printf("Popped %d from the stack\n", pop(sp)); // Last in First Out
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Peeked value at position 2: %d\n", peek(sp, 2));
    printf("Peeked value at position 4: %d\n", peek(sp, 4));
    printf("Peeked value at position 5: %d\n", peek(sp, 5));
    printf("After push, Full: %d\n", isFull(sp));
    printf("After push, Full: %d\n", isEmpty(sp));
    return 0;
}