#include <stdio.h>

int valley(int A[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == 0 || A[mid] < A[mid - 1]) && (mid == n - 1 || A[mid] < A[mid + 1]))
        {
            return mid + 1;
        }
        else if (mid > 0 && A[mid - 1] < A[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
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
    printf("%d ", valley(a, sizeof(a) / sizeof(a[0])));
}