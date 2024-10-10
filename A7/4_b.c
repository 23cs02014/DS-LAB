#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

    for(int i = 1 ; i < n-1 ; i+=2){
        if(i==n-1){
            break;
        }
        if(a[i-1]<a[i] && a[i]>a[i+1]){
            continue;
        }
        else if(a[i-1]>a[i] && a[i]> a[i+1]){
            swap(&a[i-1],&a[i]);
        }
        else if(a[i-1]<a[i] && a[i] < a[i+1]){
            swap(&a[i+1],&a[i]);
        }
        else if(a[i-1] > a[i+1]){
            swap(&a[i-1],&a[i]);
        }
        else if(a[i-1] < a[i+1]){
            swap(&a[i+1],&a[i]);
        }

    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}