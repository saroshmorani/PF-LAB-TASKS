#include <stdio.h>
#include <string.h>

struct Invoice {
    char part_number[20];
    char part_description[50];
    int quantity;
    float price_per_item;

    float calculate_invoice_amount() {
        if (quantity<0) {
            quantity=0;
        }
        if (price_per_item<0) {
            price_per_item=0;
        }
        return quantity*price_per_item;
    }
};

int main() {
    struct Invoice item;

    printf("Enter part number: ");
    scanf("%19s", item.part_number);

    printf("Enter part description: ");
    scanf(" %[^\n]s", item.part_description);

    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter price per item: ");
    scanf("%f", &item.price_per_item);

    float total_amount = item.calculate_invoice_amount();

    printf("\nInvoice Details:\n");
    printf("Part Number: %s\n", item.part_number);
    printf("Part Description: %s\n", item.part_description);
    printf("Quantity: %d\n", item.quantity);
    printf("Price per Item: $%.2f\n", item.price_per_item);
    printf("Total Invoice Amount: $%.2f\n", total_amount);

    return 0;
}

