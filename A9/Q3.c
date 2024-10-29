#include<stdio.h>

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
void Karyheapify(int n , int k , int a[n]){

}
void printArr(int n,int a[n]){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
}
int main(){
    printf("Enter K:");
    int k;
    scanf("%d", &k);
    printf("Enter N:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d",&a[i]);
    }
    for(int i = n/k - 1; i >= 0; i--){
        Karyheapify(n,i,a);
    }
    printArr(n,a);
}