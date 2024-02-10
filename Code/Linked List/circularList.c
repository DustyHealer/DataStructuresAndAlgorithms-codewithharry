#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("Head\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    do
    {
        p = p->next;
        i++;
    } while (i != index - 1 && p != head);
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, int nodeValue, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->data != nodeValue)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
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
    head->data = 4;
    head->next = second;

    // Link second and third struct Nodes
    second->data = 3;
    second->next = third;

    // Terminate the list at the third struct Node
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third struct Node
    fourth->data = 1;
    fourth->next = head; // Circular linked list: Last element points back to head

    printf("List before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 10);
    // head = insertAtFirst(head, 18);
    // head = insertAtFirst(head, 19);
    // head = insertAtIndex(head, 2, 27);
    // head = insertAtIndex(head, 2, 37);
    // head = insertAtIndex(head, 4, 37);
    // head = insertAtEnd(head, 54);
    // head = insertAtEnd(head, 59);
    head = insertAfterNode(head, 4, 8);
    head = insertAfterNode(head, 6, 16);
    printf("List after insertion\n");
    linkedListTraversal(head);
    return 0;
}