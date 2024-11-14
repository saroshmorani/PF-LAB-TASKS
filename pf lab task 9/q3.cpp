#include<stdio.h>
#include<string.h>
char login(char *username, char *password){
	if(strcmp(username, "admin")==0 && strcmp(password,"1234")==0){
		printf("\nAccess Granted");
	}
	else{
		printf("\nAccess denied");
	}
}
int main(){
	char password[20];
	char username[20];
	printf("Enter username: ");
	scanf("%s", &username);
	printf("\nEnter password: ");
	scanf("%s", &password);
	login(username, password);
}
