#include <stdio.h>

// Function prototypes
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement bubble sort and print index of swaps
void bubbleSort(int arr[], int n) {
    printf("\nUsing Bubble sort\n\n");
    int i, j, temp;
    int totalswaps = 0;
    int indexswap[n];
    for(int i = 0; i < n; i++){
        indexswap[i] = 0;
    }
    for (i = 0; i < n-1; i++) {
        printf("Iteration# %d\n", i+1);
        int swaps = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // then swap
                indexswap[j]++;
                indexswap[j+1]++;
                swaps++;
                totalswaps++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Print index of swaps
                printf("Swapped indices: %d %d\n", j, j+1);
            }
            printArray(arr, n);
        }
    }

    printf("\ntotal number of swaps: %d", totalswaps);
    for(int i = 0; i < n; i++){
        printf("\n%d was swapped %d times", arr[i], indexswap[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[] = {97, 16, 45, 63, 13, 12, 7, 58, 72};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before sorting: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}