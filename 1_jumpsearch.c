TIME COMPLEXITY-O(sqrt (n))
#include <stdio.h>
#include <math.h>

// Function to perform jump search
// Returns the index of the key element if found, -1 otherwise
int jumpSearch(int arr[], int n, int key, int *count) {
    int step = sqrt(n); // Step size
    int prev = 0;

    // Finding the interval where the key may be present
    while (arr[(int)fmin(step, n) - 1] < key) {
        (*count)++;
        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;
    }

    // Performing linear search in the interval found above
    while (arr[prev] < key) {
        (*count)++;
        prev++;

        if (prev == fmin(step, n))
            return -1;
    }

    if (arr[prev] == key) {
        (*count)++;
        return prev;
    }

    return -1;
}

int main() {
    int t; // Number of test cases
    scanf("%d", &t);

    while (t--) {
        int n, key; // Array size and key element
        scanf("%d", &n);

        int arr[n]; // Sorted array of positive integers
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        scanf("%d", &key);

        int count = 0; // Counter for number of comparisons
        int index = jumpSearch(arr, n, key, &count);

        if (index == -1)
            printf("Not Present ");
        else
            printf("Present ");

        printf("%d\n", count);
    }

    return 0;
}
