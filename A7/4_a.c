#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {

        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
void swap(int*a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int main()
{
    printf("no of elements:");
    int n;
    scanf(" %d", &n);
    printf("enter elements:");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    for(int i = 1 ; i < n-1 ; i+=2){
        swap(&a[i],&a[i+1]);
    }
    for (int i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}