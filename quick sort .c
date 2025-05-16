#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int A[], int lb, int ub) {
    int start = lb;
    int end = ub;
    int pivot = A[start];

    if (start < end) {
        while (start < end) {
            while (A[start] <= pivot ) {
                start++;
            }
            while (A[end] > pivot) {
                end--;
            }
            if (start < end) {
                swap(&A[start], &A[end]);
            }
        }

        swap(&A[lb], &A[end]);

        sort(A, lb, end - 1);
        sort(A, end + 1, ub);
    }
}

int main() {
    int A[] = {35, 78, 25, 88, 98, 23, 17};
    int n = sizeof(A) / sizeof(A[0]);

    sort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}