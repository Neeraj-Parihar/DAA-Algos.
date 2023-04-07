/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array*/
TIME COMPLEXITY-O(nlogn)
  #include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high, int* comparisons, int* swaps) {
    // Select a random pivot element
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    // Move the pivot element to the end of the array
    swap(&arr[pivotIndex], &arr[high]);
    *swaps += 1;
    int i = low - 1;
    // Partition the array based on the pivot element
    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            *swaps += 1;
        }
    }
    // Move the pivot element to its correct position in the sorted array
    swap(&arr[i + 1], &arr[high]);
    *swaps += 1;
    return i + 1;
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high, int* comparisons, int* swaps) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int pivotIndex = partition(arr, low, high, comparisons, swaps);
        // Recursively sort the two subarrays
        quicksort(arr, low, pivotIndex - 1, comparisons, swaps);
        quicksort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
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
        int comparisons = 0;
        int swaps = 0;
        srand(time(NULL));
        quicksort(arr, 0, n - 1, &comparisons, &swaps);
        // Print the sorted array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\ncomparisons = %d\nswaps = %d\n", comparisons, swaps);
    }
    return 0;
}
