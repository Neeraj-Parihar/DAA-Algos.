/*You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))*/
#include <stdio.h>

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
}

int main() {
    int m, n;
    scanf("%d", &m);
    int arr1[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &n);
    int arr2[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    findCommonElements(arr1, m, arr2, n);
    return 0;
}
