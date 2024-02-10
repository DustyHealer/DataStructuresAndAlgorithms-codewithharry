#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void traversal(struct stack *ptr);
int isEmpty(struct stack *ptr);
int isFull(struct stack *ptr);
void push(struct stack *ptr, char value);
char pop(struct stack *ptr);
char stackTop(struct stack *ptr);
char stackBottom(struct stack *ptr);
char *infixToPostfix(char *infixExpression);
int precedence(char ch);
int isOperator(char ch);

int main()
{
    char *exp = "x-y/z-k*d";
    printf("Postfix of %s is %s\n", exp, infixToPostfix(exp));
    return 0;
}

char *infixToPostfix(char *infixExpression)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infixExpression);
    sp->top = -1;
    sp->arr = (char *)malloc((sp->size) * sizeof(char));
    char *postfixExpression = (char *)malloc((strlen(infixExpression) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infixExpression[i] != '\0')
    {
        if (!isOperator(infixExpression[i]))
        {
            postfixExpression[j] = infixExpression[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infixExpression[i]) > precedence(stackTop(sp)))
            {
                push(sp, infixExpression[i]);
                i++;
            }
            else
            {
                postfixExpression[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp))
    {
        postfixExpression[j] = pop(sp);
        j++;
    }

    postfixExpression[j] = '\0';
    return postfixExpression;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

void traversal(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Traversal not possible, stack is empty\n");
    }
    else
    {
        printf("Updated stack:\n");
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("%c\n", ptr->arr[i]);
        }
    }
    return;
}

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

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Cannot push %c, stack is full\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    return;
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow, cannot pop\n");
        return '0';
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

char stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

char stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}