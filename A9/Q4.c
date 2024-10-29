#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Karyheapify(int n, int k, int a[n], int i)
{
    int largest = i;
    for (int j = 1; j <= k; j++)
    {
        int child = k * i + j;
        if (child < n && a[child] > a[largest])
        {
            largest = child;
        }
    }
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        Karyheapify(n, k, a, largest);
    }
}

void printArr(int n, int a[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter K:");
    int k;
    scanf(" %d", &k);

    printf("Enter no of elements in H1:");
    int n1;
    scanf(" %d", &n1);
    int H1[n1];
    printf("Enter the elements in H1:");
    for (int i = 0; i < n1; i++)
    {
        scanf(" %d", &H1[i]);
    }

    printf("Enter elements in H2:");
    int n2;
    scanf(" %d", &n2);
    int H2[n2];
    printf("Enter the elements in H2:");
    for (int i = 0; i < n2; i++)
    {
        scanf(" %d", &H2[i]);
    }

    int H3[n1+n2];
    for(int i = 0 ; i < n1 ; i++){
        H3[i] = H1[i];
    }
    for(int i = 0 ; i < n2 ; i++){
        H3[i+n1] = H2[i];
    }

    for (int i = (n1+n1 - 1) / k; i >= 0; i--)
    {
        Karyheapify(n1+n2, k, H3, i);
    }
    printf("Merged Heap:");
    printArr(n1+n2, H3);
    printf(" \n");
    return 0;
}