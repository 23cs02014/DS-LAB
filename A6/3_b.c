#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{

    // Initialize pivot to be the first element
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        // half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int nlognmissing(int a[], int size)
{
    quickSort(a, 0, size - 1);
    int i;
    int min = a[0];
    int max = a[size - 1];
    for (i = 0; i < size; i++)
    {
        if (a[i] != i + min)
        {
            return i + min;
        }
    }
    return -1;
}
int main()
{
    printf("Number of elements in array:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    printf(" %d", nlognmissing(a, sizeof(a) / sizeof(a[0])));
    return 0;
}