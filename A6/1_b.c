#include <stdio.h>

int nrep(int a[], int size)
{
    int f[10];
    int order[10];
    for (int i = 0; i < 10; i++)
    {
        order[i] = -1;
        f[i] = 0;
    }
    for (int i = 0, j = 0; i < size; i++)
    {
        f[a[i]]++;
        if (f[a[i]] >= 1)
        {
            order[j++] = a[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {

        if (f[a[i]] == 2 && order[i] != -1)
        {
            // printf("%d:%d ",i,order[i]);
            return a[i];
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
        scanf("%d", &a[i]);
    }

    printf(" %d\n", nrep(a, sizeof(a) / sizeof(a[0])));

    return 0;
}