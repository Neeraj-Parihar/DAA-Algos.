//TIME COMPLEXITY-O(nlogn)
/*Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n)).*/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right, int *comparisons, int *swaps) {
    int sizeL = mid - left + 1;
    int sizeR = right - mid;
    int L[sizeL], R[sizeR];
    int i, j, k;
    for (i = 0; i < sizeL; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < sizeR; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < sizeL && j < sizeR) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*swaps)++;
        }
        k++;
    }
    while (i < sizeL) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < sizeR) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int *comparisons, int *swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

int hasDuplicates(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    mergeSort(arr, 0, n - 1, &comparisons, &swaps);
    for (int i = 1; i < n; i++) {
        comparisons++;
        if (arr[i] == arr[i - 1]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        if (hasDuplicates(arr, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
