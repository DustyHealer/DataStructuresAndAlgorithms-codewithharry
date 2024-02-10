#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *ptr);
int isFull(struct queue *ptr);
struct queue *initialize(int size);
void printQueue(struct queue *ptr);
void enqueueFront(struct queue *ptr, int val);
void enqueueRear(struct queue *ptr, int val);
int dequeueFront(struct queue *ptr);
int dequeueRear(struct queue *ptr);

int main()
{
    struct queue *dq = initialize(10);
    enqueueRear(dq, 10);
    enqueueRear(dq, 20);
    enqueueRear(dq, 30);
    enqueueRear(dq, 40);
    // enqueueRear(dq, 50);
    // enqueueRear(dq, 60);
    // enqueueRear(dq, 70);
    // enqueueRear(dq, 80);
    // enqueueRear(dq, 90);
    // enqueueRear(dq, 100);
    // enqueueRear(dq, 110);
    printQueue(dq);

    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printf("Dequeue Element from front: %d\n", dequeueFront(dq));
    // printQueue(dq);

    // enqueueFront(dq, 50);
    // enqueueFront(dq, 40);
    // enqueueFront(dq, 30);
    // enqueueFront(dq, 20);
    // enqueueFront(dq, 10);
    // printQueue(dq);

    printf("Dequeue Element from rear: %d\n", dequeueRear(dq));
    printf("Dequeue Element from rear: %d\n", dequeueRear(dq));
    printf("Dequeue Element from rear: %d\n", dequeueRear(dq));
    printf("Dequeue Element from rear: %d\n", dequeueRear(dq));
    printf("Dequeue Element from rear: %d\n", dequeueRear(dq));
    printQueue(dq);

    return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

struct queue *initialize(int size)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

void printQueue(struct queue *ptr)
{
    printf("Printing Queue: \n");
    for (int i = ptr->front + 1; i <= ptr->rear; i++)
    {
        printf("%d - ", ptr->arr[i]);
    }
    printf("\n");
}

void enqueueFront(struct queue *ptr, int val)
{
    if (ptr->front == -1)
    {
        printf("Cannot Enqueue from front because no empty space\n");
    }
    else
    {
        ptr->arr[ptr->front] == val;
        ptr->front--;
        printf("%d enqueued from front\n", val);
    }
}

void enqueueRear(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Cannot Enqueue from rear because queue is full\n");
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
        printf("%d enqueued from rear\n", val);
    }
}

int dequeueFront(struct queue *ptr)
{
    int val = -1;
    if (isEmpty(ptr))
    {
        printf("Cannot dequeue from rear because queue is empty\n");
    }
    else
    {
        ptr->front++;
        val = ptr->arr[ptr->front];
    }
    return val;
}

int dequeueRear(struct queue *ptr)
{
    int val = -1;
    if (ptr->rear == -1)
    {
        printf("Cannot dequeue because no element in rear\n");
    }
    else
    {
        val = ptr->arr[ptr->rear];
        ptr->rear--;
    }
    return val;
}