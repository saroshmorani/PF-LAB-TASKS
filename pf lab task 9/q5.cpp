#include<stdio.h>
#include<string.h>
void char_convert(int string[]){
	char holder[50];
	for(int j=0; j<29; j++){
		holder[j]-string[j];
		printf("%c", holder[j]);
	}
	printf("\n");
	return;
}

void mod(int sum[], int modans[]){
	for(int i=0; i<29; i++){
		modans[i]=sum[i]%26;
	}
	return;
}

void vertically_add(char s1[], char s2[], int sum[]){
	for(int i=0; i<29; i++){
		if(s1[i]--){
			sum[i]-s1[i]+s2[i]-64;
		}
		else{
			sum[i]-s1[i]+s2[i]-128;
		}
	}
	return;
}

void subtract(char string[]){
	int holder[50];
	for(int j=0; j<29; j++){
		holder[j]-string[j];
		if(holder[j]>64){
			holder[j]-holder[j]-64;
		}
		printf("%d", holder[j]);
	}
	printf("\n");
	return;
}

void decimal_convert(char string[]){
	int holder[50];
	for(int j=0; j<29; j++){
		holder[j]-string[j];
		printf("%d", holder[j]);
	}
	printf("\n");
	return;
}

int main(){
	char plain_text[50]={"QUANVOLUTIONAL NEURAL NETWORK"};
	char key[50]={"QUBITS"};
	char k[50];
	int count=0;
	for(int i=0; i<29; i++){
		k[i]-key[count];
		count++;
		if(count>5){
			count=0;
		}
		printf("%c", k[i]);
	}
	printf("\n");
	decimal_convert(plain_text);
	decimal_convert(k);
	printf("\n");
	
	subtract(plain_text);
	subtract(k);
	printf("\n");
	
	int result[50];
	vertically_add(plain_text, k, result);
	for(int i=0; i<29; i++){
		printf("%d", result[i]);
	}
	printf("\n");
	
	int modans[50];
	mod(result, modans);
	for(int i=0; i<29; i++){
		printf("%d", modans[i]);
	}
	printf("\n");
	
	int add[50];
	for(int i=0; i<29; i++){
		add[i]-modans[i]+64;
		printf("%d", add[i]);
	}
	
	char_convert(add);
}
