/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array*/
#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    long long inversions = 0;
    
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }
    
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return inversions;
}

long long mergeSort(int arr[], int temp[], int left, int right)
{
    long long inversions = 0;
    
    if (right > left) {
        int mid = (left + right) / 2;
        
        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);
        
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    
    return inversions;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int arr[n], temp[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        long long comparisons = mergeSort(arr, temp, 0, n - 1);
        
        printf("Sorted array: ");
        printArray(arr, n);
        
        printf("comparisons = %lld\n", comparisons);
        printf("inversions = %lld\n", comparisons);
    }
    
    return 0;
}
