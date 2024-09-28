#include <stdio.h>
int main() {
    int number, a=0;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number & 1) {
        a++;
    }
    if (number & 2) {
        a++;
    }
    if (number & 4) {
        a++;
    }
     if (number & 8) {
        a++;
    }
    if (number & 16) {
        a++;
    }
    if (number & 32) {
        a++;
    }
    if (number & 64) {
        a++;
    }
    if (number & 128) {
        a++;
    }
    if (number & 256) {
        a++;
    }
    if (number & 512) {
        a++;
    }
    if (number & 1024) {
        a++;
    }
    if (number & 2048) {
        a++;
    }
    if (number & 4096) {
        a++;
    }
    if (number & 8192) {
        a++;
    }
    printf("The number of 1s in the binary representation are %d\n", a);
}
