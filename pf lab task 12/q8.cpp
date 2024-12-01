#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the total number of points in the facility: ");
    scanf("%d", &n);

    float *fees = (float *)malloc(n * sizeof(float));

    printf("Enter fee for each point:\n");
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter fee for point %d: $", i + 1);
            scanf("%f", &fees[i]);

            if (fees[i] >= 0) {
                break;
            } else {
                printf("Fee cannot be negative. Please enter a valid fee.\n");
            }
        }
    }

    float total_profit = 0.0;
    for (int i = 0; i < n; i++) {
        total_profit += fees[i];
    }

    printf("Total Profit for the Facility: $%.2f\n", total_profit);

    free(fees);

    return 0;
}
