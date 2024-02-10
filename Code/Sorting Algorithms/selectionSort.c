#include <stdio.h>

// Selection sort is not stable because order changes when the numbers are equal
// Selection sort is not adaptive because number of comparisons remains same
void printArray(int a[], int n);
void selectionSort(int *a, int n);
void swap(int *a, int *b);

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(a, n);
    selectionSort(a, n);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *a, int n)
{
    int indexOfMin;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        swap(&a[i], &a[indexOfMin]);
        printf("Array after pass %d: ", i + 1);
        printArray(a, n);
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