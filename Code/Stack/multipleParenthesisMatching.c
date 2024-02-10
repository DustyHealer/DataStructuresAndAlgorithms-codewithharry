#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Expression = 7-(8(3*9))+11+12))-8)
*/

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
int parenthesisMatch(char *exp);
int validatePoppedParenthesis(char a, char b);

int main()
{
    char inputExpression[] = "((8){(9-8)})";
    parenthesisMatch(inputExpression);
    return 0;
}

int parenthesisMatch(char *inputExpression)
{
    struct stack *parenthesis = (struct stack *)malloc(sizeof(struct stack));
    parenthesis->size = strlen(inputExpression); // In worst case all the chars in the input string will be parenthesis
    printf("The size allocated to the parenthesis array is: %d\n", parenthesis->size);
    parenthesis->top = -1;
    parenthesis->arr = (char *)malloc((parenthesis->size) * sizeof(char));
    // Iterate over the input expression
    int i = 0, totalOperations = 0;
    while (inputExpression[i] != '\0')
    {
        if (inputExpression[i] == '(' || inputExpression[i] == '{' || inputExpression[i] == '[')
        {
            totalOperations++;
            push(parenthesis, inputExpression[i]);
            // traversal(parenthesis);
            printf("Pushed %c value into the stack\n", inputExpression[i]);
        }
        else if (inputExpression[i] == ')' || inputExpression[i] == '}' || inputExpression[i] == ']')
        {
            totalOperations++;
            if (isEmpty(parenthesis))
            {
                printf("Expression is imbalanced since closing bracket is present without an opening bracket, Total operations: %d\n", totalOperations);
                return 0;
            }
            char value = pop(parenthesis);
            printf("Popped %c value from the stack\n", value);
            if (!validatePoppedParenthesis(value, inputExpression[i]))
            {
                printf("Expression is imbalanced since closing bracket is not matching with popped bracket, Total operations: %d\n", totalOperations);
                return 0;
            }
        }
        i++;
    }

    if (isEmpty(parenthesis))
    {
        printf("Expression is balanced, total operations performed: %d\n", totalOperations);
        return 1;
    }
    else
    {
        printf("Expression is imbalanced, total operations performed: %d\n", totalOperations);
        return 0;
    }
}

int validatePoppedParenthesis(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
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