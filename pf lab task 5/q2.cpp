#include<stdio.h>
int main() {
	int a,b,c;
	printf("Enter the first angle\n");
	scanf("%d", &a);
	printf("Enter the second angle\n");
	scanf("%d", &b);
	printf("Enter the third angle\n");
	scanf("%d", &c);
	if(a<=0 || b<=0 || c<=0) {
		printf("Invalid Input\n");
	}
	else if(a+b+c==180) {
		printf("The triangle is valid\n");
	}
	return 0;
}
