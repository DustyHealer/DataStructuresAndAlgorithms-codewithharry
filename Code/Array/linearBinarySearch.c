#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (high >= low)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
    // int arr[] = {1, 3, 5, 56, 4, 3, 23, 5, 4, 54, 98, 34};
    // Sorted array for binary search
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 444;
    // int searchIndex = linearSearch(arr, size, element);
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d found at index %d", element, searchIndex);
    return 0;
}