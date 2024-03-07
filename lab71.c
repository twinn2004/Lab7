#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, item, j;
    int totalswaps = 0;
    int indexswaps[n];
    for (int i = 0; i < n; i++) {
        indexswaps[i] = 0;
    }

    for (i = 1; i < n; i++) {
        item = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > item) {
            totalswaps++;
            indexswaps[j]++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = item;
    }

    printf("\nTotal swaps: %d\n", totalswaps);
    printf("Swaps per index:\n");
    for (i = 0; i < n; i++) {
        printf("%d had %d number of swaps\n", arr[i], indexswaps[i]);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]); // size of the array
    printf("Before sorting: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("\nAfter sorting: ");
    printArray(arr, n);
    return 0;
}