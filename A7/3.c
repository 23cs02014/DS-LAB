#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b);

int main() {
    printf("enter M:");
    int m;
    scanf(" %d", &m);
    printf("enter N:");
    int n;
    scanf(" %d", &n);

    printf("enter elements in first array:");
    int M[m + n];
    for (int i = 0; i < m; i++) {
        scanf(" %d", &M[i]);
    }
    // for (int i = m; i < m + n; i++) {
    //     M[i] = INT_MIN;
    // }

    printf("enter elements in second array:");
    int N[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &N[i]);
    }

    int i = m + n - 1, j = n - 1, k = m - 1;
    while (i >= 0) {
        if (k < 0) {
            while (j >= 0) {
                M[i--] = N[j--];
            }
            break;
        }
        if (j < 0) {
            while (k >= 0) {
                M[i--] = M[k--];
            }
            break;
        }
        if (M[k] >= N[j]) {
            M[i--] = M[k--];
        } else {
            M[i--] = N[j--];
        }
    }

    printf("after merging:");
    for (int i = 0; i < m + n; i++) {
        printf(" %d", M[i]);
    }
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}