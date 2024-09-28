#include<stdio.h>

int main() {
	int a, b;
	printf("Enter first and second integer");
	scanf("%d %d", &a, &b);
	printf(" %d %d",a,b);
	if(a>b)
	{
		if(a>100){
			printf("First number is significantly larger");
		}
	}
	if(a<b)
	{
		if(a<0){
			printf("First number is negative and smaller");
		}
	}
	else if(a==b)
	{
		printf("Both numbers are equal");
	}
}
