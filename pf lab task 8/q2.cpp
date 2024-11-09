#include <stdio.h>

int main() {
    int grades[4][4];
    int i, j;

    printf("Enter the grades of 4 students in 4 subjects:\n");
    for (i=0; i<4; i++) {
    	printf("\nGrade for student %d", i+1);
        for (j=0; j<4; j++) {
            printf("\nsubject %d: ", j+1);
            scanf("%d", &grades[i][j]);
        }       
    }

    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (grades[i][j]<0) {
                grades[i][j]=0;
            }
        }
    }

    printf("\nUpdated Grades Matrix:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("%d ", grades[i][j]);
        }
        printf("\n");
    }

    return 0;
}

