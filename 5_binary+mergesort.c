/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void binarySearch(int arr[], int left, int right, int key) {
    int mid;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            printf("%d ", mid + 1);
            return;
        }
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    printf("No Element Exist ");
}

int main() {
    int t, n, i, key;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d", &n);
        int arr[n];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &key);
        
        mergeSort(arr, 0, n - 1);
        
        for (i = 0; i < n - 1; i++) {
            binarySearch(arr, i + 1, n - 1, key - arr[i]);
            if (i < n - 2)
                printf("& ");
            else
                printf("\n");
        }
    }
    
    return 0;
}
