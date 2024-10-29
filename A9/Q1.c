#include<stdio.h>

void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
void printArr(int n,int a[n]){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
    }
}
int main(){
    printf("Enter the number of elements in the array:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of min heap:");
    for(int i = 0 ; i < n ; i++){
        scanf(" %d",&a[i]);
    }
    printArr(n,a);
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    //heapify(a,n,n);
    printf("\n");
    printArr(n,a);
}