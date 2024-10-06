#include <stdio.h>
#include <math.h>
int main() {
    int a, b, remainder, result = 0, i = 0;

    printf("Enter an integer: ");
    scanf("%d", &a);

    b = a;
    
    while (b != 0) {
        b /= 10;
        ++i;
    }

    b = a;

    while (b != 0) {
        remainder = b % 10;
        result += pow(remainder, i);
        b /= 10;
    }

    if (result == a) {
        printf("%d is an Armstrong number.\n", a);
    } else {
        printf("%d is not an Armstrong number.\n", a);
    }

    return 0;
}
