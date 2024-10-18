#include <stdio.h>

int main() {
    int a[] = {1, 1, 1, 1, 1, 5, 1, 1, 1, 1};
    int size = sizeof(a) / sizeof(a[0]);
    int number, b = 0, i;

    printf("Enter integer to search: ");
    scanf("%d", &number);

    for(i = 0; i < size; i++) {
        if(a[i] == number) {
            printf("%d found at index %d\n", number, i);
            b = 1;
            break;
        }
    }

    if (b == 0) {
        printf("Number not found\n");
    }

    return 0;
}

