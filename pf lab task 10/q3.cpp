#include <stdio.h>
#include <string.h>

struct cars {
    char model[50];
    int year;
    int price;
    float mileage;
};

void printcars(struct cars c) {
    printf("Model: %s\nYear: %d\nPrice: %d\nMileage: %.2f\n", c.model, c.year, c.price, c.mileage);
}

int main() {
    int n;
    printf("How many entries? ");
    scanf("%d", &n);
    
    struct cars car;
    for (int i = 0; i < n; i++) {
        printf("\nModel: ");
        scanf("%s", car.model);
        printf("Year: ");
        scanf("%d", &car.year);
        printf("Price: ");
        scanf("%d", &car.price);
        printf("Mileage: ");
        scanf("%f", &car.mileage);
        
        printcars(car);
    }
    return 0;
}

