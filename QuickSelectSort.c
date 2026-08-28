#include <stdio.h>

// 1. Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 3. QuickSelect function
int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pi = partition(arr, low, high);
    if (k == pi) {
        return arr[pi];
    } else if (k < pi) {
        return quickSelect(arr, low, pi - 1, k);
    } else {
        return quickSelect(arr, pi + 1, high, k);
    }
}

// 4. Main function
int main() {
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Find the 2nd smallest element
    printf("The %dth smallest element is %d\n", k, quickSelect(arr, 0, n - 1, k - 1));
    
    return 0;
}