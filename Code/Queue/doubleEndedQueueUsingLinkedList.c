#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty();
int isFull();
void initialize();
void printQueue();
void enqueueFront(int val);
void enqueueRear(int val);
int dequeueFront();
int dequeueRear();

int main()
{
    enqueueFront(40);
    enqueueRear(50);
    enqueueFront(30);
    enqueueRear(60);
    enqueueFront(20);
    enqueueRear(70);
    printQueue();

    printf("Dequeue Front Successful: %d\n", dequeueFront());
    printf("Dequeue Rear Successful: %d\n", dequeueRear());
    printf("Dequeue Front Successful: %d\n", dequeueFront());
    printf("Dequeue Rear Successful: %d\n", dequeueRear());
    printQueue();

    return 0;
}

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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

void printQueue()
{
    struct node *ptr = front;
    printf("Printing Queue: \n");
    while (ptr != NULL)
    {
        printf("%d =>", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void enqueueFront(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Cannot Enqueue, Queue is full\n");
    }
    else
    {
        ptr->data = val;
        if (front == NULL)
        {
            ptr->next = NULL;
            front = rear = ptr;
        }
        else
        {
            ptr->next = front;
            front = ptr;
        }
        printf("Enqueue Front Successful: %d\n", val);
    }
}

void enqueueRear(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Cannot Enqueue, Queue is full\n");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
        printf("Enqueue Rear Successful: %d\n", val);
    }
}

int dequeueFront()
{
    int val = -1;
    struct node *ptr = front;
    if (isEmpty())
    {
        printf("Cannot Enqueue, Queue is empty\n");
    }
    else
    {
        val = front->data;
        front = front->next;
        free(ptr);
    }
    return val;
}

int dequeueRear()
{
    int val = -1;
    struct node *p = front;
    struct node *q = rear;
    if (isEmpty())
    {
        printf("Cannot Enqueue, Queue is empty\n");
    }
    else
    {
        val = rear->data;
        while (p->next != rear)
        {
            p = p->next;
        }
        p->next = NULL;
        rear = p;
        free(q);
    }
    return val;
}