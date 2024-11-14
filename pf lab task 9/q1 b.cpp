#include<stdio.h>

int pattern(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			printf("%d", j+1);
		}
	for(int k=i+1; k>0; k--){
			printf("%d", k);
		}
		printf("\n");
	}
}

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	pattern(n);
}
