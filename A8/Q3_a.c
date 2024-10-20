#include<stdio.h>

int main(){
    printf("Enter n:");
    int n;
    scanf(" %d", &n);

    int a[n],b[n];
    printf("Enter elements of first array:");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d", &a[i]);
    }
    printf("Enter elements of second array:");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d", &b[i]);
    }
    int f[2][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(f[0][j]==a[i]){
                
            }
        }
    }

}