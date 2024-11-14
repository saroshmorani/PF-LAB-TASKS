#include <stdio.h>

void check(int nuts, int bolts, int washers) {
    if (nuts >= bolts && washers >= 2 * bolts) {
        printf("The order is OK\n");
    }
	else if (nuts < bolts && washers < 2 * bolts) {
        printf("Too few nuts and Too few washers.\n");
    }
	else if (nuts < bolts) {
		printf("Too few nuts.\n");
    } 
	else if (washers < 2 * bolts) {
        printf("Too few washers.\n");
    }
}

int sum(int nuts, int bolts, int washers) {
    int A, B, C, total;
    A = 5 * bolts;
    B = 3 * nuts;
    C = washers;
    total = A + B + C;
    return total;
}

int main() {
    int nuts, bolts, washers;
    
    printf("Number of bolts:      ");
    scanf("%d", &bolts);
    
    printf("Number of nuts:       ");
    scanf("%d", &nuts);
    
    printf("Number of washers:    ");
    scanf("%d", &washers);
    
    printf("Check the order: ");
    check(nuts, bolts, washers);
    
    int total = sum(nuts, bolts, washers);
    printf("Total cost: %d\n", total);
    
}

