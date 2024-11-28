#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 50

struct Student {
    int id;
    char name[50];
};

struct Course {
    int id;
    char name[50];
    char instructor[50];
    int credits;
    int student_count;
    struct Student students[MAX_STUDENTS];
};

struct Department {
    int id;
    char name[50];
    int course_count;
    struct Course courses[MAX_COURSES];
};

struct University {
    int department_count;
    struct Department departments[MAX_DEPARTMENTS];
};

void add_department(struct University *university) {
    if (university->department_count >= MAX_DEPARTMENTS) {
        printf("Maximum departments reached.\n");
        return;
    }

    struct Department new_department;
    printf("Enter Department ID: ");
    scanf("%d", &new_department.id);
    printf("Enter Department Name: ");
    scanf(" %[^\n]s", new_department.name);

    new_department.course_count = 0;
    university->departments[university->department_count++] = new_department;

    printf("Department added successfully.\n");
}

void add_course(struct University *university) {
    int dept_id, i;
    printf("Enter Department ID: ");
    scanf("%d", &dept_id);

    for (i = 0; i < university->department_count; i++) {
        if (university->departments[i].id == dept_id) {
            if (university->departments[i].course_count >= MAX_COURSES) {
                printf("Maximum courses reached in this department.\n");
                return;
            }

            struct Course new_course;
            printf("Enter Course ID: ");
            scanf("%d", &new_course.id);
            printf("Enter Course Name: ");
            scanf(" %[^\n]s", new_course.name);
            printf("Enter Instructor Name: ");
            scanf(" %[^\n]s", new_course.instructor);
            printf("Enter Credits: ");
            scanf("%d", &new_course.credits);

            new_course.student_count = 0;
            university->departments[i].courses[university->departments[i].course_count++] = new_course;

            printf("Course added successfully.\n");
            return;
        }
    }

    printf("Department not found.\n");
}

void enroll_student(struct University *university) {
    int dept_id, course_id, i, j;
    printf("Enter Department ID: ");
    scanf("%d", &dept_id);

    for (i = 0; i < university->department_count; i++) {
        if (university->departments[i].id == dept_id) {
            printf("Enter Course ID: ");
            scanf("%d", &course_id);

            for (j = 0; j < university->departments[i].course_count; j++) {
                if (university->departments[i].courses[j].id == course_id) {
                    if (university->departments[i].courses[j].student_count >= MAX_STUDENTS) {
                        printf("Maximum students reached in this course.\n");
                        return;
                    }

                    struct Student new_student;
                    printf("Enter Student ID: ");
                    scanf("%d", &new_student.id);
                    printf("Enter Student Name: ");
                    scanf(" %[^\n]s", new_student.name);

                    university->departments[i].courses[j].students[university->departments[i].courses[j].student_count++] = new_student;

                    printf("Student enrolled successfully.\n");
                    return;
                }
            }

            printf("Course not found.\n");
            return;
        }
    }

    printf("Department not found.\n");
}

void display_university(struct University *university) {
    printf("\nUniversity Data:\n");

    for (int i = 0; i < university->department_count; i++) {
        struct Department *dept = &university->departments[i];
        printf("Department ID: %d, Name: %s\n", dept->id, dept->name);

        for (int j = 0; j < dept->course_count; j++) {
            struct Course *course = &dept->courses[j];
            printf("  Course ID: %d, Name: %s, Instructor: %s, Credits: %d\n",
                   course->id, course->name, course->instructor, course->credits);

            for (int k = 0; k < course->student_count; k++) {
                struct Student *student = &course->students[k];
                printf("    Student ID: %d, Name: %s\n", student->id, student->name);
            }
        }
    }
}

int main() {
    struct University university;
    university.department_count = 0;

    int choice;

    do {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course\n");
        printf("3. Enroll Student\n");
        printf("4. Display University Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_department(&university);
                break;
            case 2:
                add_course(&university);
                break;
            case 3:
                enroll_student(&university);
                break;
            case 4:
                display_university(&university);
                break;
            case 5:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

