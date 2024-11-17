#include <stdio.h>

void quicksort(int arr[], int left, int right);

int main() {
    int a[100], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j]; //swapping i and j if crossed
            arr[j] = temp;
        }
    }

    // Place pivot in the correct position
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    // Recursively sort the left and right parts
    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
}
