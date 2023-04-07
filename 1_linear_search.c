//TIME COMPLEXITY-O(n).
#include <stdio.h>

int linearSearch(int arr[], int n, int key, int* comparisons) {
    int i;
    for (i = 0; i < n; i++) {
        *comparisons += 1; // Incrementing the comparison count for each iteration
        if (arr[i] == key) {
            return i+1; // Returning the position of the key if found
        }
    }
    return -1; // Returning -1 if key not found
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t);
    while (t--) {
        int n, key, comparisons = 0;
        scanf("%d", &n);
        int arr[n], i;
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &key);
        int pos = linearSearch(arr, n, key, &comparisons);
        if (pos == -1) {
            printf("Not Present %d\n", comparisons);
        } else {
            printf("Present %d\n", comparisons);
        }
    }
    return 0;
}
