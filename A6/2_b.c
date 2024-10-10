#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
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

int main()
{
    printf("Elements in array:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
        {
            printf("%d ", a[i]);
            i++;
        }
        // printf("%d ", a[i]);
    }
    return 0;
}