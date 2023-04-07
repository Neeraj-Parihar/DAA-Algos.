//TIME COMPLEXITY-O(n^2)
/*Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
total number of times the array elements are shifted from their place) required for sorting the
array.*/
#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    int i, key, j;
    *comparisons = 0;
    *shifts = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        (*comparisons)++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*shifts)++;
            (*comparisons)++;
        }
        arr[j + 1] = key;
        (*shifts)++;
    }
}

int main() {
    int T, n, arr[1000], comparisons, shifts;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        insertionSort(arr, n, &comparisons, &shifts);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\nComparisons = %d\nShifts = %d\n", comparisons, shifts);
    }

    return 0;
}
