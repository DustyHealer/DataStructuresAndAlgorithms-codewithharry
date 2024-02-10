#include <stdio.h>

int arr[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
int arraySize = 9;

// Selection sort is not stable because order changes when the numbers are equal
// Selection sort is not adaptive because number of comparisons remains same
void printArray(int a[], int n);
void merge(int *a, int mid, int low, int high);
void mergeSort(int *a, int low, int high);

int main()
{
    printArray(arr, arraySize);
    int low = 0;
    int high = arraySize - 1;
    mergeSort(arr, low, high);
    printArray(arr, arraySize);
    return 0;
}

void merge(int *a, int mid, int low, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
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