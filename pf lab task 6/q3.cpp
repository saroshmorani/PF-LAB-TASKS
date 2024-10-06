#include<stdio.h>
int main() {
	int a;
	do{
		printf("Enter a positive Integer\n");
		scanf("%d", &a);
		if(a<0){
			printf("NOOO!!\n");
		}
	}while(a<1);
	printf("YAYY! the positive integer is %d\n", a);
	return 0;
}
