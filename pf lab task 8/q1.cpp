#include<stdio.h>
int main(){
	int matrix[3][3];
	int row[3]={0,0,0};
	int column[3]={0,0,0};
	
	printf("Enter the scores: ");
	for(int i=0; i<3; i++){
		printf("\nparticipant %d: \n", i+1);
		for(int j=0; j<3; j++){
			printf("activity %d: ", j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");
	
	for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            row[i]=row[i]+matrix[i][j];
            column[j]=column[j]+matrix[i][j];
        }
    }
    
    for(int i=0; i<3; i++){
		printf("\nparticipant %d total score: %d ", i+1, row[i]);
	}
	for(int j=0; j<3; j++){
			printf("\nactivity %d total score: %d", j+1, column[j]);
		}
	return 0;
}
