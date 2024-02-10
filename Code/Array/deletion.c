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

int indexDeletion(int arr[], int size, int capacity, int index)
{
    // Code for insertion
    if (size >= capacity || index > capacity - 1)
    {
        return 0;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int capacity = 100, size = 5, element = 45, index = 0;
    int arr[100] = {7, 8, 12, 27, 78};
    display(arr, size);

    // Element insertion at the given index
    if (indexDeletion(arr, size, capacity, index))
    {
        printf("Element deleted successfully\n");
        size--;
        display(arr, size);
    }
    else
    {
        printf("Insertion Failed..\n");
    }

    return 0;
}