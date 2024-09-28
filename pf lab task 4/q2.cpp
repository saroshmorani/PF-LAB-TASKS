#include<stdio.h>
int main() {
	int units;
	float totalbill, surcharge;
	
	printf("Enter the electricity units\n");
	scanf("%d", &units);
	if(units<=30 && units>=0) {
		totalbill = units * 0.60;
	}
	else if(units>=110) {
		totalbill = (30 * 0.60) + ((units-30) * 0.85);
	}
	else if(units>=210) {
		totalbill = (30 * 0.60) + (80 * 0.85) + ((units-110) * 1.30);
	}
	else {
		totalbill = (30 * 0.60) + (80 * 0.85) + (100 * 1.30) + ((units-210) * 1.60);
	}
	surcharge = units * 0.15;
	totalbill += surcharge;
	printf("your total bill including surcharge is %2f\n", totalbill);
	
	return 0;
}
