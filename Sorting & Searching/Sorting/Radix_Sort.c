#include <stdio.h>
void countingSort(int arr[], int n, int pos)
{
    int count[10] = {0};
    int temp[n];
    int i;

    for (i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
void radixSort(int arr[], int n)
{
    int maxElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    for (int pos = 1; maxElement / pos > 0; pos *= 10)
    {
        countingSort(arr, n, pos);
    }
}
int main()
{
    int arr[] = {245, 20, 95, 7, 356, 412, 3, 68};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The main array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    radixSort(arr, n);

    printf("\nThe sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}