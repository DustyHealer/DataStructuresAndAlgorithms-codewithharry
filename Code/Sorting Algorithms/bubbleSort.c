#include <stdio.h>

// Intermediate result is useful in bubble sort because we get largest element
// We have to write extra code to make this adaptive
void printArray(int a[], int n);
void bubbleSort(int *a, int n);
void swap(int *a, int *b);

int main()
{
    // int a[] = {12, 54, 65, 7, 23, 9};
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printArray(a, n);
    bubbleSort(a, n);
    return 0;
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

void bubbleSort(int *a, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass
    {
        isSorted = 1;
        for (int j = 0; j <= n - 1 - i; j++) // For comparison in each pass
        {
            if (a[j] > a[j + 1])
            {
                isSorted = 0;
                swap(&a[j], &a[j + 1]);
            }
        }
        printf("Array after %d pass: \n", i + 1);
        printArray(a, n);
        if (isSorted)
        {
            return;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}