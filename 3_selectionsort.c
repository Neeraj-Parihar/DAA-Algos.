TIME COMPLEXITY-O(n^2)
  /*Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.*/
  #include <stdio.h>

void selectionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        (*swaps)++;
    }
}

int main() {
    int t, n, i, j, comparisons, swaps;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        int arr[n];
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        comparisons = 0;
        swaps = 0;
        selectionSort(arr, n, &comparisons, &swaps);
        printf("\nSorted Array: ");
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\ncomparisons = %d\nswaps = %d\n", comparisons, swaps);
    }
    return 0;
}
