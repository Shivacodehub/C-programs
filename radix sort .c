#include <stdio.h>

#define MAX 100

void radixSort(int a[], int n) {
    int bucket[10][MAX];
    int noeb[10]; 
    int div = 1;
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int steps = 1;
    while (max / div > 0) {
        for (int i = 0; i < 10; i++)
            noeb[i] = 0;
         for (int j = 0; j < n; j++) {
            int loc = (a[j] / div) % 10;
            bucket[loc][noeb[loc]++] = a[j];
        }
        int k = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < noeb[i]; j++) {
                a[k++] = bucket[i][j];
            }
        }

        div *= 10;
        steps++;
    }
}

int main() {
    int arr[] = {50, 23, 108, 85, 12, 93, 5, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radixSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}