#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void doubleLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    // Printing elements left to right
    printf("NULL <=> %d <=> ", ptr->data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        printf("%d <=> ", ptr->data);
    }
    printf("NULL <=> ");

    // Printing elements reverse right to left
    while (ptr != NULL)
    {
        printf("%d <=> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
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
    head->prev = NULL;
    head->next = second;

    // Link second and third struct Nodes
    second->data = 11;
    second->prev = head;
    second->next = third;

    // Terminate the list at the third struct Node
    third->data = 41;
    third->prev = second;
    third->next = fourth;

    // Terminate the list at the third struct Node
    fourth->data = 66;
    fourth->prev = third;
    fourth->next = NULL;

    doubleLinkedListTraversal(head);
    return 0;
}