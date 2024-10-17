#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter lenght of array:");
    int n;
    scanf(" %d",&n);
    int a[n];
    printf("Enter values:");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d",&a[i]);
        printf("%d ",a[i]);
    }
}