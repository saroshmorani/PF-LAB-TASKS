#include<stdio.h>
int main() {
	int a;
	printf("Enter your Age\n");
	scanf("%d", &a);
	if (a==18 || a>18) {
	int citizen;
	printf("Are you a Pakistani Citizen?\n");
	printf("Press 1 for yes\n");
	printf("Press 0 for no\n");
	scanf("%d", &citizen);
		if (citizen==1) {
			printf("You are eligible to vote\n");
		}
		else {
			printf("You are not eligible to vote\n");
		}
	}
	else {
		printf("You are not eligible to vote");
	}
	return 0;
}
