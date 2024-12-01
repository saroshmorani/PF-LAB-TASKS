#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *n, int pos, int val) {
    if (pos < 0 || pos > *n) {
        printf("Invalid position\n");
        return;
    }
    *arr = (int *)realloc(*arr, (*n + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = *n - 1; i >= pos; i--) {
        (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[pos] = val;
    (*n)++;
}

void del(int **arr, int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*n)--;
    if (*n == 0) {
        free(*arr);
        *arr = NULL;
    } else {
        *arr = (int *)realloc(*arr, (*n) * sizeof(int));
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 0, val, pos;
    int *arr = NULL;

    while (1) {
        printf("Enter operation (1: insert, 2: delete, 3: print, 4: exit): ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insert(&arr, &n, pos, val);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                del(&arr, &n, pos);
                break;
            case 3:
                printArray(arr, n);
                break;
            case 4:
                free(arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

