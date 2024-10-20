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
        //printf("%d ",a[i]);
    }
    printf("Enter K:");
    int k;
    scanf(" %d",&k);
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            for(int l = j + 1 ; l < n ; l++){
                if(a[i]+a[j]+a[l] == k){
                    printf("%d %d %d \n", a[i],a[j],a[l]);
                }
            }
        }
    }
} 