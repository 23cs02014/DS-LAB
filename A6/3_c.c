#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int naturalSum(int n)
{
    return n * (n + 1) / 2;
}
int nmissing(int a[], int size)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int sum1 = naturalSum(max) - naturalSum(min - 1);
    int sum2 = 0;
    for (int i = 0; i < size; i++)
    {
        sum2 += a[i];
    }
    return sum1 - sum2;
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
    printf(" %d", nmissing(a, sizeof(a) / sizeof(a[0])));
    return 0;
}