#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Predefined array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int pairSum[size / 2]; // Array to store the sums of pairs

    // Loop through the array with a step of 2 to sum adjacent elements
    for(int i = 0; i < size; i += 2) {
        pairSum[i / 2] = arr[i] + arr[i + 1]; // Sum adjacent elements and store
    }

    // Print the resulting array of pair sums
    printf("Pair Sum array: ");
    for(int i = 0; i < size / 2; i++) {
        printf("%d ", pairSum[i]); // Print pair sums
    }
    printf("\n");

    return 0; // End the program
}

