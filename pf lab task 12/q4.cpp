#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int *A = (int*)malloc(N * sizeof(int));
        if (A == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        int *freq = (int*)calloc(10001, sizeof(int));
        if (freq == NULL) {
            printf("Memory allocation failed.\n");
            free(A);
            return 1;
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            freq[A[i]]++;
        }
        
        int maxFreq = 0;
        int result = 10001;
        
        for (int i = 1; i <= 10000; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                result = i;
            } else if (freq[i] == maxFreq && i < result) {
                result = i;
            }
        }
        
        printf("%d\n", result);
        
        free(A);
        free(freq);
    }
    
    return 0;
}

