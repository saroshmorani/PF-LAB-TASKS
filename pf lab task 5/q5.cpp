#include<stdio.h>
int main() {
	int a;
	printf("Enter an integer\n");
	scanf("%d", &a);
	(a%2==0)? printf("%d is an even number\n", a):
		printf("%d is an odd number\n", a);
}
