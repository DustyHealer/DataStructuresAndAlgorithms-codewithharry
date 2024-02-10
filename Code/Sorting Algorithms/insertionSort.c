#include <stdio.h>

// Intermediate result is not useful in insertion sort
// Insertion sort is adaptive by default
void printArray(int arr[], int size);
void insertionSort(int *arr, int size);

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printf("Initial Array: ");
    printArray(a, n);
    insertionSort(a, n);
    return 0;
}

void insertionSort(int *arr, int size)
{
    int key, j;
    for (int i = 1; i <= size - 1; i++) // Loop for creating each pass (n-1)
    {
        // Code for each pass
        printf("Starting code for Pass %d: ", i);
        printArray(arr, size);
        key = arr[i]; // Key to be inserted
        j = i - 1;    // Start the comparison with the previous values
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            printArray(arr, size);
            j--;
        }
        arr[j + 1] = key;

        printf("Ending code for Pass %d: ", i);
        printArray(arr, size);
    }
}

void printArray(int arr[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}