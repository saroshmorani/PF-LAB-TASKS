#include <stdio.h>

struct phone {
    int area_code;
    int exchange;
    int number;
};

int main() {
    struct phone mynumber = {212, 767, 8900};
    struct phone yournumber;

    printf("Enter area code: ");
    scanf("%d", &yournumber.area_code);

    printf("Enter exchange: ");
    scanf("%d", &yournumber.exchange);

    printf("Enter number: ");
    scanf("%d", &yournumber.number);

    printf("My number is (%d) %d-%d\n", mynumber.area_code, mynumber.exchange, mynumber.number);
    printf("Your number is (%d) %d-%d\n", yournumber.area_code, yournumber.exchange, yournumber.number);

    return 0;
}

