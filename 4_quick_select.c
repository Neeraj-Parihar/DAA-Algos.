/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/
#include <stdio.h>

// Swap two elements in an array
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition the array around the pivot element and return its index
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

// Find the Kth smallest element in the array
int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int idx = partition(arr, l, r);
        if (idx - l == k - 1) {
            return arr[idx];
        }
        if (idx - l > k - 1) {
            return kthSmallest(arr, l, idx - 1, k);
        }
        return kthSmallest(arr, idx + 1, r, k - idx + l - 1);
    }
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &k);
        int kth = kthSmallest(arr, 0, n - 1, k);
        if (kth != -1) {
            printf("%d\n", kth);
        } else {
            printf("not present\n");
        }
    }
    return 0;
}
