#include <stdio.h>

int main() {
    int n;
    int i, j, k;
    printf("Enter a number: ");
	scanf("%d", &n);

    for (i=0; i<n; i++) {
        for (j=0; j<i; j++) {
            printf(" ");
        }
        for (k=n-i; k>=1; k--) {
            printf("%d ", k);
        }
        printf("\n");
    }

    for (i = n-2; i>=0; i--) {
        for (j=0; j<i; j++) {
            printf(" ");
        }
        for (k=n-i; k>=1; k--) {
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}

