#include<stdio.h>
int main() {
	int a;
	do{
		printf("Enter an integer\n");
		scanf("%d", &a);
		
		if(a!=0) {
			printf("You entered %d. Try Again!\n", a);
		}
	}while(a!=0);
	printf("You guessed it!\n");
}
