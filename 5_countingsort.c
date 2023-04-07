/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)*/
#include <stdio.h>
#include <string.h>

// Function to find the alphabet with maximum occurrences
void max_occurrences(char arr[], int n) {
    // Initialize a count array with all elements as 0
    int count[26] = {0};
    int max_count = 0, max_index = 0;

    // Traverse through the input array and increment the count of each alphabet
    for (int i = 0; i < n; i++) {
        count[arr[i] - 'a']++;
    }

    // Find the alphabet with maximum occurrences
    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_index = i;
        }
    }

    // If all elements occur only once
    if (max_count == 1) {
        printf("No Duplicates Present\n");
    }
    else {
        printf("%c - %d\n", max_index + 'a', max_count);
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char arr[n];
        for (int i = 0; i < n; i++) {
            scanf(" %c", &arr[i]);
        }

        max_occurrences(arr, n);
    }

    return 0;
}

