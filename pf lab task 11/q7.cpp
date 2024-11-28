#include <stdio.h>
#include <string.h>

struct Course {
    char course_id[10];
    char course_name[50];
    char instructor_name[50];
    int credits;
};

struct Department {
    char department_name[50];
    struct Course courses[10];
    int course_count;
};

struct University {
    struct Department departments[10];
    int department_count;
};

void add_department(struct University *uni) {
    if (uni->department_count >= 10) {
        printf("Maximum number of departments reached.\n");
        return;
    }
    printf("Enter department name: ");
    scanf(" %[^\n]s", uni->departments[uni->department_count].department_name);
    uni->departments[uni->department_count].course_count = 0;
    uni->department_count++;
    printf("Department added successfully.\n");
}

void add_course(struct University *uni) {
    if (uni->department_count == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    printf("Select a department:\n");
    for (int i = 0; i < uni->department_count; i++) {
        printf("%d. %s\n", i + 1, uni->departments[i].department_name);
    }

    int dept_choice;
    printf("Enter department number: ");
    scanf("%d", &dept_choice);

    if (dept_choice < 1 || dept_choice > uni->department_count) {
        printf("Invalid department choice.\n");
        return;
    }

    struct Department *dept = &uni->departments[dept_choice - 1];

    if (dept->course_count >= 10) {
        printf("Maximum number of courses for this department reached.\n");
        return;
    }

    struct Course *new_course = &dept->courses[dept->course_count];
    printf("Enter course ID: ");
    scanf(" %[^\n]s", new_course->course_id);
    printf("Enter course name: ");
    scanf(" %[^\n]s", new_course->course_name);
    printf("Enter instructor name: ");
    scanf(" %[^\n]s", new_course->instructor_name);
    printf("Enter course credits: ");
    scanf("%d", &new_course->credits);

    dept->course_count++;
    printf("Course added successfully to %s department.\n", dept->department_name);
}

void display_university(struct University *uni) {
    if (uni->department_count == 0) {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < uni->department_count; i++) {
        struct Department *dept = &uni->departments[i];
        printf("\nDepartment: %s\n", dept->department_name);
        printf("Courses:\n");
        if (dept->course_count == 0) {
            printf("  No courses available.\n");
        } else {
            for (int j = 0; j < dept->course_count; j++) {
                struct Course *course = &dept->courses[j];
                printf("  %s - %s (Instructor: %s, Credits: %d)\n",
                       course->course_id, course->course_name,
                       course->instructor_name, course->credits);
            }
        }
    }
}

void calculate_total_credits(struct University *uni) {
    if (uni->department_count == 0) {
        printf("No departments available.\n");
        return;
    }

    for (int i = 0; i < uni->department_count; i++) {
        struct Department *dept = &uni->departments[i];
        int total_credits = 0;
        for (int j = 0; j < dept->course_count; j++) {
            total_credits += dept->courses[j].credits;
        }
        printf("Total credits for %s department: %d\n", dept->department_name, total_credits);
    }
}

int main() {
    struct University uni = {0};

    int choice;
    do {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Display Departments and Courses\n");
        printf("4. Calculate Total Credits per Department\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_department(&uni);
                break;
            case 2:
                add_course(&uni);
                break;
            case 3:
                display_university(&uni);
                break;
            case 4:
                calculate_total_credits(&uni);
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

