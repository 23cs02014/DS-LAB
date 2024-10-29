#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Karyheapify(int n, int k, int a[n], int i) {
    int largest = i;
    for (int j = 1; j <= k; j++) {
        int child = k * i + j;
        if (child < n && a[child] > a[largest]) {
            largest = child;
        }
    }
    if (largest != i) {
        swap(&a[i], &a[largest]);
        Karyheapify(n, k, a, largest);
    }
}

void printArr(int n, int a[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter K:");
    int k;
    scanf("%d", &k);
    printf("Enter N:");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = (n - 1) / k; i >= 0; i--) {
        Karyheapify(n, k, a, i);
    }
    printArr(n, a);
    return 0;
}