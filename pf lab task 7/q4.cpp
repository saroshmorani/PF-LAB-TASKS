#include<stdio.h>

int main() {
int i;
int integer[20];
for(i = 1; i<=20; i++){
printf("Enter integer %d = ", i);
scanf("%d", &integer[i]);
}
printf("The reverse order is:\n");
for(i=20; i>=1; i--)
printf("%d\n", integer[i]);

return 0;
}
