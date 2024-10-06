#include <stdio.h>

void FS(int number2) {
    int b = 0, c = 1, next;
    printf("Fibonacci Series up to %d:\n", number2);
    printf("%d, %d, ", b, c);
    for (int i = 3; i <= number2; i++) {
        next = b + c;
        printf("%d, ", next);
        b = c;
        c = next;
    }
}

int main() {
    int number, i, a = 1;

    printf("Enter a Number\n");
    scanf("%d", &number);

    if (number <= 0) {
        a = 0;
    } else {
        for (i = 2; number/2 >= i; i++) {
            if (number % i == 0) {
                a = 0;
            }
        }
    }

    if (a) {
        printf("%d is a prime number\n", number);
        FS(number);
    } else {
        printf("%d is not a prime number\n", number);
    }

    return 0;
}
