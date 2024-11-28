#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "books.txt"

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
    float price;
};

void add_book() {
    FILE *file = fopen(FILE_NAME, "a+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book new_book;
    printf("Enter Book ID: ");
    scanf("%d", &new_book.id);

    struct Book temp;
    while (fread(&temp, sizeof(struct Book), 1, file)) {
        if (temp.id == new_book.id) {
            printf("Book ID already exists.\n");
            fclose(file);
            return;
        }
    }

    printf("Enter Title: ");
    scanf(" %[^\n]s", new_book.title);
    printf("Enter Author: ");
    scanf(" %[^\n]s", new_book.author);
    printf("Enter Quantity: ");
    scanf("%d", &new_book.quantity);
    printf("Enter Price: ");
    scanf("%f", &new_book.price);

    if (new_book.quantity < 0 || new_book.price < 0) {
        printf("Quantity and price must be non-negative.\n");
        fclose(file);
        return;
    }

    fwrite(&new_book, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book added successfully.\n");
}

void view_books() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    printf("\nBooks in the Library:\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
               book.id, book.title, book.author, book.quantity, book.price);
    }
    fclose(file);
}

void search_book() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    int choice;
    printf("Search by:\n1. ID\n2. Title\nEnter your choice: ");
    scanf("%d", &choice);

    struct Book book;
    int id;
    char title[50];
    int found = 0;

    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (book.id == id) {
                printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                       book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Title: ");
        scanf(" %[^\n]s", title);
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (strcmp(book.title, title) == 0) {
                printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
                       book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
    fclose(file);
}

void update_book() {
    FILE *file = fopen(FILE_NAME, "r+");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    struct Book book;
    int found = 0;
    long pos;

    while ((pos = ftell(file)) >= 0 && fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new Price: ");
            scanf("%f", &book.price);
            if (book.quantity < 0 || book.price < 0) {
                printf("Quantity and price must be non-negative.\n");
                fclose(file);
                return;
            }
            fseek(file, pos, SEEK_SET);
            fwrite(&book, sizeof(struct Book), 1, file);
            printf("Book details updated successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
    fclose(file);
}

void delete_book() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    FILE *temp_file = fopen("temp.txt", "w");
    struct Book book;
    int found = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1;
        } else {
            fwrite(&book, sizeof(struct Book), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("Book not found.\n");
    }
}

void calculate_total_inventory_value() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No books available.\n");
        return;
    }

    struct Book book;
    float total_value = 0;

    while (fread(&book, sizeof(struct Book), 1, file)) {
        total_value += book.quantity * book.price;
    }

    printf("Total Inventory Value: %.2f\n", total_value);
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                update_book();
                break;
            case 5:
                delete_book();
                break;
            case 6:
                calculate_total_inventory_value();
                break;
            case 7:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

