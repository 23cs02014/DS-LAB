#include <stdio.h>

int n2rep(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i] == a[j])
            {
                return a[i];
            }
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
    printf(" %d", n2rep(a, sizeof(a) / sizeof(a[0])));
    return 0;
}