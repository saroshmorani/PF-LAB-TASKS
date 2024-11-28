#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    char dob[11];
    int id;
    char department[50];
    float salary;
};

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int num_employees = 0;
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 1;
                if (num_employees < MAX_EMPLOYEES) {
                    printf("\nEnter Employee Details:\n");
                    printf("Name: ");
                    scanf("%s", employees[num_employees].name);
                    printf("Date of Birth (DD/MM/YYYY): ");
                    scanf("%s", employees[num_employees].dob);
                    printf("Employee ID: ");
                    scanf("%d", &employees[num_employees].id);
                    printf("Department: ");
                    scanf("%s", employees[num_employees].department);
                    printf("Salary: ");
                    scanf("%f", &employees[num_employees].salary);
                    num_employees++;
                    printf("\nEmployee added!\n");
                } else {
                    printf("\nMaximum reached.\n");
                }
                break;

            case 2:
                if (num_employees > 0) {
                    int id_to_delete;
                    printf("\nEnter Employee ID to Delete: ");
                    scanf("%d", &id_to_delete);
                    int found = 0;
                    for (int i = 0; i < num_employees; i++) {
                        if (employees[i].id == id_to_delete) {
                            for (int j = i; j < num_employees - 1; j++) {
                                employees[j] = employees[j + 1];
                            }
                            num_employees--;
                            found = 1;
                            printf("\nEmployee deleted!\n");
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nEmployee ID not found.\n");
                    }
                } else {
                    printf("\nNo employees to delete.\n");
                }
                break;

            case 3:
                if (num_employees > 0) {
                    printf("\nEmployee List:\n");
                    printf("-------------------------------------------------\n");
                    printf("Name\t\tDOB\t\tID\tDepartment\tSalary\n");
                    printf("-------------------------------------------------\n");
                    for (int i = 0; i < num_employees; i++) {
                        printf("%s\t\t%s\t%d\t%s\t%.2f\n", employees[i].name, employees[i].dob, employees[i].id, employees[i].department, employees[i].salary);
                    }
                    printf("-------------------------------------------------\n");
                } else {
                    printf("\nNo employees to display.\n");
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
