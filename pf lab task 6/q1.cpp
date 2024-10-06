#include<stdio.h>
int main() {
	int number, a=1, i;
	
	printf("Enter a positive integer\n");
	scanf("%d", &number);
	
	if(number<0) {
		printf("the integer is negative-INVALID integer");
	}
	for(i=1; i<=number; i++) {
			a*=i;
    	}
    	printf("factorial of %d = %d", number, a);
    	return 0;

}
