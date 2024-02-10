#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Self referencing struct
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for struct Nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link head and second struct Nodes
    head->data = 7;
    head->next = second;

    // Link second and third struct Nodes
    second->data = 11;
    second->next = third;

    // Terminate the list at the third struct Node
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third struct Node
    fourth->data = 66;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}