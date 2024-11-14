#include<stdio.h>
#include<string.h>
void search(char name[5][20], char *input){
	int found=0;
	for (int i=0; i<5; i++){
		if(strcmp(name[i],input)==0){
			printf("found\n");
			found=1;
			break;
		}
	}
	if(found==0){
		printf("not found\n");
	}
}

int main(){
	char name[5][20] = {"Alice", "Harry", "Charlie", "Diana", "Eve"};
	char input[100];
	printf("Enter a Name to search: ");
	scanf("%s", &input);
	search(name,input);
	
}
