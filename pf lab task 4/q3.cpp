#include<stdio.h>
int main() {
	int totalcost;
	float amountsaved, amountafterdiscount;
	
	printf("Enter the cost of all the items\n");
	scanf("%d", &totalcost);
	
	if(totalcost<=1500 && totalcost>=0) {
		amountsaved = totalcost * 0.07;
	}
	else if(totalcost<=3000 && totalcost>1500) {
		amountsaved = totalcost * 0.12;
	}
	else if(totalcost<=5000 && totalcost>3000) {
		amountsaved = totalcost * 0.22;
	}
	else if(totalcost>5000) {
		amountsaved = totalcost * 0.30;
	}
	printf("The original amount was %d\n", totalcost);
	printf("The amount saved is %2f\n", amountsaved);
	
	amountafterdiscount= totalcost - amountsaved;
	printf("The total amount after discount is %2f\n", amountafterdiscount);
}
