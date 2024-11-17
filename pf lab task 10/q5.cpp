#include <stdio.h>

int sum_of_digits(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + sum_of_digits(num / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int result = sum_of_digits(number);
    printf("\nThe sum of digits of %d is: %d\n", number, result);

    return 0;
}

