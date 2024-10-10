#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int n2missing(int a[], int size)
{
    bubbleSort(a, size);
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
    // n2missing(a, sizeof(a) / sizeof(a[0]));

    printf(" %d", n2missing(a, sizeof(a) / sizeof(a[0])));
    return 0;
}