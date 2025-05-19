#include <stdio.h>
#define MAX 100

void countingSort(int arr[], int n) {
    int output[MAX];
    int count[MAX] = {0};

    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // Store the count of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    countingSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}