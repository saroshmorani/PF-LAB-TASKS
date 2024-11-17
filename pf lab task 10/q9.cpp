#include <stdio.h>
#include <string.h>

struct employee {
    int ID;
    char name[50];
    char department[50];
    float salary;
};

void display(struct employee e[], int n) {
    printf("\nEmployee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", e[i].ID);
        printf("Name: %s\n", e[i].name);
        printf("Department: %s\n", e[i].department);
        printf("Salary: %.2f\n\n", e[i].salary);
    }
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee data[n];

    for (int i = 0; i < n; i++) {
        printf("\nDetails for employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &data[i].ID);
        printf("Employee name: ");
        scanf(" %[^\n]%*c", data[i].name);
        printf("Employee department: ");
        scanf(" %[^\n]%*c", data[i].department);
        printf("Employee salary: ");
        scanf("%f", &data[i].salary);
    }

    display(data, n);

    return 0;
}

