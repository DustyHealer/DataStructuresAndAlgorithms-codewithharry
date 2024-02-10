#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void printArray(int *arr, int size)
{
    printf("Visited: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printQueue(struct queue *q)
{
    printf("Exploration Queue: ");
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Cannot Enqueue: Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Cannot Dequeue: Queue is empty\n");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}

int main(void)
{
    struct queue *explorationQueue = (struct queue *)malloc(sizeof(struct queue));
    explorationQueue->size = 40;
    explorationQueue->f = explorationQueue->r = -1;
    explorationQueue->arr = (int *)malloc(explorationQueue->size * sizeof(int));

    int source = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacencyMatrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                                 {1, 0, 1, 0, 0, 0, 0},
                                 {1, 0, 0, 1, 1, 0, 0},
                                 {1, 1, 1, 0, 1, 0, 0},
                                 {0, 0, 1, 1, 0, 1, 1},
                                 {0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0}};
    visited[source] = 1;
    printArray(visited, 7);
    enqueue(explorationQueue, source);
    printQueue(explorationQueue);

    while (!isEmpty(explorationQueue))
    {
        int node = dequeue(explorationQueue);
        printQueue(explorationQueue);
        for (int j = 0; j < 7; j++)
        {
            if (adjacencyMatrix[node][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                printArray(visited, 7);
                enqueue(explorationQueue, j);
                printQueue(explorationQueue);
            }
        }
    }
    return 0;
}