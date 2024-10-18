#include <stdio.h>

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(A[0]);
    int firstnumber = A[0];

    printf("Before: ");
    for(int i = 0; i < size; i++) {
        printf("%d", A[i]);
    }
	printf("\n");  

    for(int i = 0; i < size - 1; i++) {
        A[i] = A[i + 1];
    }
    A[size - 1] = firstnumber;

    printf("After: ");
    for(int i = 0; i < size; i++) {
        printf("%d", A[i]);
    }

    return 0;
}

