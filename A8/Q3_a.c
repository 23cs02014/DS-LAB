#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int countOccurrences(int arr[], int n, int element) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

_Bool checkSameElements(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (countOccurrences(a, n, a[i])!= countOccurrences(b, n, a[i])) {
            return false;
        }
    }
    return true;
}

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
    if(checkSameElements(a, b, n)){
        printf("Same\n");
    }
    else{
        printf("Diff\n");
    }

} 