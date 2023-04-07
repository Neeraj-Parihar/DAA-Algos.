/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.*/
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d", &n);
        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        scanf("%d", &k);
        
        int count = 0;
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i]-arr[j] == k || arr[j]-arr[i] == k)
                    count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
