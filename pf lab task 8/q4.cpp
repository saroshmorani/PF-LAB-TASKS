#include <stdio.h>

int main() {
    int m, n;
    int i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int mat1[m][n], mat2[m][n], result[m][n];

    printf("Enter elements of the first matrix:\n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("Matrix after addition:\n");
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

