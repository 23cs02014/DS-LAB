#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
    int hash[1000] = {0};
    for(int i = 0 ; i < n ; i++){
        hash[a[i] + 500]++;
    }
    // for(int i = 0 ; i < n ; i++){
    //     printf("%d ",hash[a[i]]);
    // }
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int x = k-a[i]-a[j];
            if(x >= 0 && hash[x+500] > 0){
                if(x == a[i] || x == a[j]){
                    if(hash[x+500] > 1){
                        printf("%d %d %d \n", a[i],a[j],x);
                    }
                }
                else if(x != a[i] && x != a[j]){
                printf("%d %d %d \n", a[i],a[j],x);
            }
            }
        }
    }
} 