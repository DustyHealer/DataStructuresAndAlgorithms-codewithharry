#include <stdio.h>
#include <stdlib.h>

/*
Case 1: Deleting the first node
Case 2: Deleting a node in between
Case 3: Delete the last node
Case 4: Delete a node with the given value
*/

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
    printf("NULL\n");
    return;
}

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteNodeAtIndex(struct Node *head, int index)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    q = head->next;

    int i = 0;
    while (i != index - 1 && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    q = head->next;

    int i = 0;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteNodeWithValue(struct Node *head, int value)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    q = head->next;

    int i = 0;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
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

    printf("Linked list before deletion\n");
    linkedListTraversal(head);
    // head = deleteFirstNode(head);
    // head = deleteNodeAtIndex(head, 2);
    // head = deleteLastNode(head);
    head = deleteNodeWithValue(head, 41);
    printf("Linked list After deletion\n");
    linkedListTraversal(head);
    return 0;
}