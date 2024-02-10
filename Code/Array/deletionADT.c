#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int total_size;
    int used_size;
    int *ptr;
} myArray;

void initializeArray(myArray *arr, int total_size, int used_size)
{
    arr->total_size = total_size;
    arr->used_size = used_size;
    arr->ptr = (int *)malloc(total_size * sizeof(int));
}

void setValues(myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter value at position %d: ", i);
        scanf("%d", &((arr->ptr)[i]));
    }
    return;
}

void printValues(myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
    printf("\n");
    return;
}

void deleteValues(myArray *arr, int index)
{
    for (int i = index; i < arr->used_size; i++)
    {
        (arr->ptr)[i] = (arr->ptr)[i + 1];
    }
    arr->used_size--; // Reduce used size since one element is deleted
}

int main()
{
    myArray rollNumbers;
    int total_size, used_size, deleteIndex;
    printf("Lets create an abstract array\n");
    printf("Please enter the total number of elements you plan to save in this array: ");
    scanf("%d", &total_size);
    printf("Please enter the total number of elements you want to enter now: ");
    scanf("%d", &used_size);
    printf("Initializing the array...\n");
    initializeArray(&rollNumbers, total_size, used_size);
    printf("Lets enter elements in the array:\n");
    setValues(&rollNumbers);
    printf("Printing the elements in the array:\n");
    printValues(&rollNumbers);
    printf("Lets delete elements from the array:\n");
    printf("Enter the index of the element you want to delete: ");
    scanf("%d", &deleteIndex);
    deleteValues(&rollNumbers, deleteIndex);
    printf("Printing the elements in the array:\n");
    printValues(&rollNumbers);
    printf("Press any key to exit........");
    getchar();
    return 0;
}