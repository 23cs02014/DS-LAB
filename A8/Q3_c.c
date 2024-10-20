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
     int hash[1000] = {0};
     //int hash2[1000] = {0};
    for(int i = 0 ; i < n ; i++){
        hash[a[i] + 500]++;
        //hash2[b[i] + 500]++;
    }
    for(int i = 0 ; i < n ; i++){
        if(hash[b[i] + 500] == 0){
            printf("Diff\n");
            return 0;
        }
        hash[b[i] + 500]--;
    }
    printf("Same\n");
    return 0;
} 