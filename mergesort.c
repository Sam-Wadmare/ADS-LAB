#include<stdio.h>

int arr[50];

void merge(int low,int mid,int high) {
    int i,left,right,temp[50];
    i=low;
    left=low;
    right=mid+1;
        while (left<=mid && right<=high) {
            if(arr[left]<=arr[right]) {
                temp[i]=arr[left];
                left++;
            }
            else{
                temp[i]=arr[right];
                right++;
            }
            i++;
        }
        while(left<=mid) {
            temp[i]=arr[left];
                left++;
        }
        while(right<=high) {
            temp[i]=arr[right];
                right++;
        }
        for(i=low;i<=high;i++) {
            arr[i]=temp[i];
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
