#include <stdio.h>
int main() {
int a, i=1;

printf("Enter a positive integer\n");
scanf("%d", &a);

if (a < 1) {
	printf("Invalid input.\n"); 
	}

else printf("the even numbers are: ");
while(i<=a) {
	if(i%2==0) {
		printf("%d\n", i);
	}
	i++;
}
return 0;

}
