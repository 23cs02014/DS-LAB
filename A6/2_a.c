#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
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
    bubblesort(a, n);
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