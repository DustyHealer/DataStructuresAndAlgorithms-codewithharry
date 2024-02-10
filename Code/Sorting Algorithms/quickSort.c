#include <stdio.h>

int arr[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
int partitionCount = 0;
int arraySize = 9;

// Selection sort is not stable because order changes when the numbers are equal
// Selection sort is not adaptive because number of comparisons remains same
void printArray(int a[], int n);
void quickSort(int *a, int low, int high);
void swap(int *a, int *b);

int main()
{
    printArray(arr, arraySize);
    int low = 0;
    int high = arraySize - 1;
    quickSort(arr, low, high);
    printArray(arr, arraySize);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        // swap a[i] and a[j]
        if (i < j)
        {
            swap(&a[i], &a[j]);
            printf("Swapping arr[%d] and arr[%d]: ", i, j);
            printArray(a, arraySize);
        }
    } while (i < j);

    // Swap a[low] and a[j]
    swap(&a[low], &a[j]);
    printf("Swapping arr[%d] and arr[%d]: ", low, j);
    printArray(a, arraySize);
    return j;
}

void quickSort(int *a, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionCount++;
        printf("Starting Partition %d\n", partitionCount);
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
}

void printArray(int a[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}