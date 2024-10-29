#include <stdio.h>
#include <stdbool.h>
#define bool _Bool
int root(int Arr[], int i)
{

    while (Arr[i] != i)

    {
        i = Arr[i];
    }
    return i;
}
bool find(int Arr[], int A, int B)
{
    if (root(Arr, A) == root(Arr, B))
        return true;
    else
        return false;
}
void Union(int Arr[], int A, int B)
{
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    Arr[root_A] = root_B;
}
void initialize(int Arr[], int N)
{

    for (int i = 0; i < N; i++)
        Arr[i] = i;
}
void printArr(int n, int a[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    printf("Number of cities(n):");
    int n;
    scanf(" %d", &n);
    printf("Enter relations (R):");
    int r[n];
    for (int i = 0; i < n * (n - 1) / 2; i++)
    {
        scanf(" %d", r + i);
    }
    int set[n];
    initialize(set, n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (r[k++])
            {
                Union(set, j, i);
            }
        }
    }
    printArr(n, set);printf("\n");
    int f[n];
    for(int i = 0 ; i < n ; i++){
        f[i]=0;
    }
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        f[set[i]]++;
        if(f[set[i]]==1){
            count++;
        }
    }
    printf("count:%d",count);
    


}