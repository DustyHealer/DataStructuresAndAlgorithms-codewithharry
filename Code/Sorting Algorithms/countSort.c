#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Count sort is one of the fastest sorting algo
void printArray(int arr_count, int *arr);
void countSort(int arr_count, int *arr);
int maximum(int arr_count, int *arr);

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(n, a);
    countSort(n, a);
    printArray(n, a);
    return 0;
}

void countSort(int arr_count, int *arr)
{
    // Find the maximum element in A
    int maxValue = maximum(arr_count, arr);

    // Create the count array
    int *countArr = (int *)malloc((maxValue + 1) * sizeof(int));

    // Initialize the array elements to zero
    for (int i = 0; i <= maxValue; i++)
    {
        countArr[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (int i = 0; i < arr_count; i++)
    {
        countArr[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxValue; i++)
    {
        if (countArr[i] > 0)
        {
            while (countArr[i] > 0)
            {
                arr[index] = i;
                index++;
                countArr[i]--;
            }
        }
    }
}

int maximum(int arr_count, int *arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr_count; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void printArray(int arr_count, int *arr)
{
    for (int i = 0; i < arr_count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}