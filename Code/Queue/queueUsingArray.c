#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size; // Size of the queue
    int f;    // Front of the queue
    int r;    // Rear of the queue
    int *arr; // Array to store the data for the queue
};

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int main()
{
    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 3;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // Check if queue is empty
    // if (isEmpty(q))
    // {
    //     printf("Queue is Empty\n");
    // }

    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 19);

    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }

    printf("Dequeue Element = %d\n", dequeue(q));
    printf("Dequeue Element = %d\n", dequeue(q));
    printf("Dequeue Element = %d\n", dequeue(q));

    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }

    return 0;
}
