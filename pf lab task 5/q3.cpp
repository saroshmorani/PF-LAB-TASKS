#include<stdio.h>
int main() {
	int marks;
	printf("Enter your marks\n");
	scanf("%d", &marks);
	(marks>=90 && marks<=100)? printf("Grade:A\n"):
	(marks>=80 && marks<=89)? printf("Grade:B\n"):
	(marks>=70 && marks<=79)? printf("Grade:C\n"):
	(marks>=60 && marks<=69)? printf("Grade:D\n"):
	(marks<60)? printf("Grade:F\n"):
		printf("Invalid Input");
}
