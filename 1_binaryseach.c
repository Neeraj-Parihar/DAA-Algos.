//TIME COMPLEXITY-O(log n)
#include <stdio.h>

// Function to perform binary search
// Returns the index of the key element if found, -1 otherwise
int binarySearch(int arr[], int n, int key, int *count) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            (*count)++;
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
            (*count)++;
        } else {
            right = mid - 1;
            (*count)++;
        }
    }

    return -1;
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        int n, key; // Array size and key element
        scanf("%d %d", &n, &key);

        int arr[n]; // Sorted array of positive integers
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        int count = 0; // Counter for number of comparisons
        int index = binarySearch(arr, n, key, &count);

        if (index == -1)
            printf("Key element not present in array\n");
        else
            printf("Key element present at index %d\n", index);

        printf("Total number of comparisons: %d\n", count);
    }

    return 0;
}
