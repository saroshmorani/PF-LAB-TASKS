#include<stdio.h>
int main() {
	int number, i, a=1;
	
	printf("Enter a Number\n");
	scanf("%d", &number);
	
	if(number<=0) {
		a=0;
	}
	else {
		for(i=2; number/2 >= i; i++) {
			if(number%i==0) {
				a=0;
				break;
			}
		}
	}
	if(a) {
		printf("%d is a prime number\n", number);
	}
	else {
		printf("%d is not a prime number\n", number);
	}
	return 0;
}
