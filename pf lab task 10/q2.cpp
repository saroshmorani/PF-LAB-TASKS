#include <stdio.h>

void Percentage(int value, int percent) {
    if (percent > value)
        return;

    printf("%d Percent = %.2f\n", percent, value * (percent / 100.0));
    Percentage(value, percent + 1);
}

int main() {
    int value;
    
    printf("Enter a value to split in percentage: ");
    scanf("%d", &value);

    Percentage(value, 1);

    return 0;
}

