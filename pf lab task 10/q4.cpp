#include <stdio.h>
#include <string.h>

struct travel {
    char travel_package[50];
    char destination[50];
    int duration;
    int cost;
    int seats;
};

void display(struct travel packages[], int n) {
    for (int i = 0; i < n; i++) {
        if (packages[i].seats > 0) {
            printf("Package: %s, Destination: %s, Duration: %d hrs, Cost: %d, Seats: %d\n", 
                   packages[i].travel_package, packages[i].destination, 
                   packages[i].duration, packages[i].cost, packages[i].seats);
        }
    }
}

void book(struct travel packages[], int n) {
    char name[50];
    printf("Enter package name to book: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < n; i++) {
        if (strcmp(packages[i].travel_package, name) == 0 && packages[i].seats > 0) {
            packages[i].seats--;
            printf("Booking confirmed for %s\n", packages[i].travel_package);
            return;
        }
    }
    printf("Package not available or full.\n");
}

int main() {
    int n;
    printf("Enter number of packages: ");
    scanf("%d", &n);

    struct travel packages[n];
    for (int i = 0; i < n; i++) {
        printf("Enter package %d details:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", &packages[i].travel_package);
        printf("Destination: ");
        scanf(" %[^\n]", &packages[i].destination);
        printf("Duration (hours): ");
        scanf("%d", &packages[i].duration);
        printf("Cost: ");
        scanf("%d", &packages[i].cost);
        printf("Seats: ");
        scanf("%d", &packages[i].seats);
    }

    int choice;
    do {
        printf("\n1. Display Packages\n2. Book Package\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            display(packages, n);
        } else if (choice == 2) {
            book(packages, n);
        }
    } while (choice != 3);

    return 0;
}

