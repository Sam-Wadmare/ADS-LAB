#include<stdio.h>

int arr[50];

void merge(int low, int mid, int high) {
    int i, left, right, temparr[50];
    left = low;
    right = mid + 1;
    i = low;

    // Merge the two halves into temparr
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temparr[i] = arr[left];
            left++;
        } else {
            temparr[i] = arr[right];
            right++;
        }
        i++;
    }

    // Copy remaining elements from the left half
    while (left <= mid) {
        temparr[i] = arr[left];
        left++;
        i++;
    }

    // Copy remaining elements from the right half
    while (right <= high) {
        temparr[i] = arr[right];
        right++;
        i++;
    }

    // Copy the sorted subarray back to the original array
    for (i = low; i <= high; i++) {
        arr[i] = temparr[i];
    }
}

void mergesort(int low, int high) {
    int mid;
    if (low < high) { // Corrected base condition
        mid = (low + high) / 2;
        mergesort(low, mid);         // Sort left half
        mergesort(mid + 1, high);    // Sort right half
        merge(low, mid, high);       // Merge both halves
    }
}

int main() {
    int n, i;

    printf("Enter number of Elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: \n", n);
    for (i = 0; i < n; i++) { // Corrected indexing
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++) { // Corrected indexing
        printf("%d ", arr[i]);
    }

    mergesort(0, n - 1); // Adjusted to 0-based indexing

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) { // Corrected indexing
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
