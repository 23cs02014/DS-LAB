#include <stdio.h>

int findFromRotatedArray(int a[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (a[mid] == target) {
            return mid;
        }
        if (a[left] <= a[mid]) {
            if (a[left] <= target && target < a[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        else {
            if (a[mid] < target && target <= a[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    printf("Enter N: ");
    int n;
    scanf("%d", &n);
    
    printf("Enter elements: ");
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter K: ");
    int k;
    scanf("%d", &k);
    printf("Element found at index: %d\n", findFromRotatedArray(a, n, k));

    
    return 0;
}