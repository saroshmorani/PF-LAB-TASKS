#include <stdio.h>
#include <stdlib.h>

void displayArray(float* arr, int size) {
    if (size == 0) {
        printf("The array is empty.\n");
    } else {
        printf("Array contents: ");
        for (int i = 0; i < size; i++) {
            printf("%.2f ", arr[i]);
        }
        printf("\n");
    }
}

float* addNumber(float* arr, int* size, int* capacity, float newNumber) {
    if (*size >= *capacity) {
        *capacity *= 2;
        arr = (float*)realloc(arr, *capacity * sizeof(float));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    arr[*size] = newNumber;
    (*size)++;
    return arr;
}

float* removeLastNumber(float* arr, int* size, int* capacity) {
    if (*size > 0) {
        (*size)--;
        if (*size <= *capacity / 4) {
            *capacity /= 2;
            arr = (float*)realloc(arr, *capacity * sizeof(float));
            if (arr == NULL) {
                printf("Memory allocation failed.\n");
                exit(1);
            }
        }
    } else {
        printf("The array is empty. No number to remove.\n");
    }
    return arr;
}

int main() {
    int capacity = 4;
    int size = 0;
    float* arr = (float*)malloc(capacity * sizeof(float));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int choice;
    float num;

    do {
        printf("\nMenu:\n");
        printf("1. Add a new number\n");
        printf("2. Display all numbers\n");
        printf("3. Remove the last number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a floating-point number to add: ");
                scanf("%f", &num);
                arr = addNumber(arr, &size, &capacity, num);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                arr = removeLastNumber(arr, &size, &capacity);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(arr);
    return 0;
}

