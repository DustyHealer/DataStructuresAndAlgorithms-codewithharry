#include <stdio.h>

int main()
{
    int first = 0, second = 0, count = 0;
    printf("Intial value of first, second and count is %d, %d and %d\n", first, second, count);

    printf("Enter the number of times the first loop will run: ");
    scanf("%d", &first);

    printf("Enter the number of times the second loop will run: ");
    scanf("%d", &second);

    for (int i = 0; i < first; i++)
    {
        for (int j = 0; j < i; j++)
        {
            count++;
        }
    }

    printf("The total number of times the loop runs is %d\n", count);

    return 0;
}