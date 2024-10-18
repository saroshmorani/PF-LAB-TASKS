#include<stdio.h>

int main() {
int i;
int integer;
int B[30];
for(i = 0; i<=29; i++){
printf("Enter integer %d = ", i+1);
scanf("%d", &B[i]);
}
int max=B[0];
for(i=0;i<max;i++) {
if(B[i]<max)
max=B[i];
}
printf(" max=%d\n", max);
int min=B[0];
for(i=0;i>min;i++) {
if(B[i]>min)
min=B[i];
}
printf(" min=%d\n", min);

return 0;
}

