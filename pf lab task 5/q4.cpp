#include<stdio.h>
int main() {
	int membership_status;
	float purchase_amount;
	printf("Press 1 if you have membership\n Press 0 if you do not have membership\n");
	scanf("%d", &membership_status);
	(membership_status==0)? printf("You are not eligible for the discount\n"):
	(membership_status==1)?
	(printf("Enter the purchase amount in dollars\n"),
	scanf("%f", &purchase_amount),
	(purchase_amount>=100)?
	printf("You are eligible for the discount\n"):
		printf("You are not eligible for the discount\n")
	):
	printf("invalid input\n");
	return 0;
}
