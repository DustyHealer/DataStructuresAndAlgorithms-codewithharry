#include <stdio.h>
#include <stdlib.h>

// ADT is Abstract Data Type

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    (*a).total_size = tSize;
    (*a).used_size = uSize;
    (*a).ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element at %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void insert(struct myArray *a, int index, int newValue)
{
    (a->used_size)++;
    for (int i = index; i < a->used_size; i++)
    {
        (a->ptr)[i + 1] = (a->ptr)[i];
    }
    (a->ptr)[index] = newValue;
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);
    printf("We are running show now\n");
    show(&marks);
    int index, newValue;
    printf("Please enter the index where new value is to be updated: ");
    scanf("%d", &index);
    printf("Please enter new value to be updated: ");
    scanf("%d", &newValue);
    insert(&marks, index, newValue);
    printf("We are running show now\n");
    show(&marks);
    return 0;
}