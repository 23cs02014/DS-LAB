#include <stdio.h>
#include <stdbool.h>

int root(int Arr[], int i) {
    while (Arr[i] != i) {
        i = Arr[i];
    }
    return i;
}

bool find(int Arr[], int A, int B) {
    return root(Arr, A) == root(Arr, B);
}

void Union(int Arr[], int A, int B) {
    int root_A = root(Arr, A);
    int root_B = root(Arr, B);
    Arr[root_A] = root_B;
}

void initialize(int Arr[], int N) {
    for (int i = 0; i < N; i++) {
        Arr[i] = i;
    }
}

void printArr(int n, int a[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    printf("Number of cities(n):");
    int n;
    scanf("%d", &n);

    printf("Enter relations (R):");
    int r[n * (n - 1) / 2];
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        scanf("%d", &r[i]);
    }

    int set[n];
    initialize(set, n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (r[k++]) {
                Union(set, j, i);
            }
        }
    }

    int f[n];
    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int root_i = root(set, i);
        if (f[root_i] == 0) {
            count++;
        }
        f[root_i]++;
    }

    printf("count: %d\n", count);

    for (int i = 0; i < n; i++) {
        if (f[i] > 0) {
            printf("Set %d: ", i);
            for (int j = 0; j < n; j++) {
                if (root(set, j) == i) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }

    return 0;
}