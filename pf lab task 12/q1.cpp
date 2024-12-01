#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents, i, j;

    printf("Enter the total number of students: ");
    scanf("%d", &numStudents);

    int* numGrades = (int*)malloc(numStudents * sizeof(int));
    float** grades = (float**)malloc(numStudents * sizeof(float*));

    for (i = 0; i < numStudents; i++) {
        printf("\nEnter the number of grades for Student %d: ", i + 1);
        scanf("%d", &numGrades[i]);

        grades[i] = (float*)malloc(numGrades[i] * sizeof(float));

        for (j = 0; j < numGrades[i]; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%f", &grades[i][j]);
        }
    }

    printf("\nEntered Student Grades:\n");
    for (i = 0; i < numStudents; i++) {
        printf("Student %d Grades: ", i + 1);
        for (j = 0; j < numGrades[i]; j++) {
            printf("%d ", (int)grades[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);
    free(numGrades);

    return 0;
}

