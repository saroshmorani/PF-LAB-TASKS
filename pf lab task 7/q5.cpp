#include <stdio.h>

int main() {
    int sum = 0;
    int i;
    int marks[15];

    for(i = 0; i < 15; i++) {
        printf("Enter integer %d = ", i + 1);
        scanf("%d", &marks[i]);
    }

    for(i = 0; i < 15; i++) { 
        sum = sum + marks[i];
    }

    printf("The sum is: %d\n", sum);

    return 0;
}

