#include<stdio.h>

int valley(int A[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == 0 || A[mid] < A[mid - 1]) && (mid == n - 1 || A[mid] < A[mid + 1]))
        {
            return mid;
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
int f(int a[],int n,int v,int t){
    
}
int main(){
    printf("Enter N:");
    int n;
    scanf(" %d", &n);
    printf("Enter elements:");
    int a[n];
    for(int i = 0 ; i < n ; i++){
        scanf(" %d",a+i);
    }
    printf(" %d \n", valley(a,n));

    return 0;
}