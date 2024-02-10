#include <stdio.h>

void display(int arr[], int n)
{
    // Code for traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indexInsertion(int arr[], int size, int element, int capacity, int index)
{
    // Code for insertion
    if (size >= capacity || index > capacity - 1)
    {
        return 0;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int capacity = 100, size = 4, element = 45, index = 3;
    int arr[100] = {1, 2, 6, 78};
    display(arr, size);

    // Element insertion at the given index
    if (indexInsertion(arr, size, element, capacity, index))
    {
        printf("Element inserted successfully\n");
        size++;
        display(arr, size);
    }
    else
    {
        printf("Insertion Failed..\n");
    }

    return 0;
}