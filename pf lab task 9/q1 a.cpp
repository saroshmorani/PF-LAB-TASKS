#include <stdio.h>

void printShape(int N) {
    int rows = 2 * N + 1;
    for (int i = 0; i < rows; i++) {
        int numSpaces = (i < N) ? (N - i) : (i - N);
        int numSymbols = rows - 2 * numSpaces;
        
        for (int j = 0; j < numSpaces; j++) {
            printf(". ");
        }
        for (int j = 0; j < numSymbols-j; j++) {
                printf("o");
			}
        
        printf("\n");
    }
    }

int main() {
    int N = 10;
    printShape(N);
    return 0;
}

