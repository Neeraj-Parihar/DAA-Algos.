/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/
//TIME COMPLEXITY-O(n^3)
#include <stdio.h>

void findTriplets(int arr[], int n) {
    int i, j, k, found = 0;
    for (i = 0; i < n-2; i++) {
        for (j = i+1; j < n-1; j++) {
            for (k = j+1; k < n; k++) {
                if (arr[i] + arr[j] == arr[k]) {
                    printf("%d, %d, %d\n", i, j, k);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("No sequence found.\n");
    }
}

int main() {
    int t, n, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int arr[n];
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        findTriplets(arr, n);
    }
    return 0;
}
