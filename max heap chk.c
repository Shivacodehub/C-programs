#include <stdio.h>
#include <stdbool.h>

// Function to check if the array represents a Max-Heap
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If left child exists and is greater than parent
        if (left < n && arr[i] < arr[left])
            return false;

        // If right child exists and is greater than parent
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

int main() {
    int arr[] = {90, 15, 10, 7, 12, 2}; // Example of a max-heap
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isMaxHeap(arr, n))
        printf("The given array represents a Max-Heap.\n");
    else
        printf("The given array does NOT represent a Max-Heap.\n");

    return 0;
}