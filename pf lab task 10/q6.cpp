#include<stdio.h>
#include<string.h>
void reverse(char name[13], int length){
	if(length<0){
		return;
	}
	else{
		printf("%c", name[length]);
		length--;
		reverse(name,length);
	}
}

int main(){
char name[13];
printf("Enter a string: ");
gets(name);

reverse(name,strlen(name));
}
