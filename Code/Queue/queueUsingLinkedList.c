#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL; // Front pointer
struct node *rear = NULL;  // Rear Pointer

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

void traversal()
{
    printf("Traversing: \n");
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Enqueue Failed: Queue is Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        printf("Enqueue Successful: %d\n", val);
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = front;
    if (isEmpty(front))
    {
        printf("Dequeue Failed: Queue is Empty\n");
    }
    else
    {
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    // Print Queue
    traversal();

    // Enqueue 3 values
    enqueue(3);
    enqueue(23);
    enqueue(12);
    // Print Queue
    traversal(front);
    printf("Front element: %d\n", front->data);
    printf("Rear element: %d\n", rear->data);

    // Dequeue 3 values
    printf("Dequeue Successful: %d\n", dequeue());
    printf("Dequeue Successful: %d\n", dequeue());
    // Print Queue
    traversal();

    printf("Dequeue Successful: %d\n", dequeue());
    // Print Queue
    traversal();

    return 0;
}