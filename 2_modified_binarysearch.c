//TIME COMPLEXITY-)(log n)
//It's a modified version of binary search
#include <stdio.h>

int binarySearch(int arr[], int n, int key, int *count)
{
    int low = 0, high = n - 1, mid, index = -1;
    *count = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        (*count)++;
        if (arr[mid] == key)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return index;
}

void findOccurrences(int arr[], int n, int key)
{
    int count, index = binarySearch(arr, n, key, &count);
    if (index == -1)
        printf("Key not present\n");
    else
    {
        int left = index, right = index;
        while (left > 0 && arr[left - 1] == key)
            left--;
        while (right < n - 1 && arr[right + 1] == key)
            right++;
        printf("%d - %d\n", key, right - left + 1);
    }
    printf("Number of comparisons: %d\n", count);
}

int main()
{
    int t, n, key, i, j;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        int arr[n];
        for (j = 0; j < n; j++)
            scanf("%d", &arr[j]);
        scanf("%d", &key);
        findOccurrences(arr, n, key);
    }
    return 0;
}
