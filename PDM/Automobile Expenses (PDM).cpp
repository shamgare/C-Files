#include <stdio.h>

double loan, ins, gas, oil, tire, maintenance, total, totalAnnual;

int countExpenses() 
{
	total = loan + ins + gas + oil + tire + maintenance;
	printf("Your total monthly expense is %.2lf\n", total);
	
	totalAnnual = total * 12;
	printf("Your total annual expense is %.2lf\n", totalAnnual);
	
	return 0;
}

int main()
{
	printf("Enter your monthly cost of loan payment: ");
	scanf("%lf", &loan);
	printf("Enter your monthly cost of insurance: ");
	scanf("%lf", &ins);
	printf("Enter your monthly cost of gas: ");
	scanf("%lf", &gas);
	printf("Enter your monthly cost of oil: ");
	scanf("%lf", &oil);
	printf("Enter your monthly cost of tires: ");
	scanf("%lf", &tire);
	printf("Enter your monthly cost of maintenance: ");
	scanf("%lf", &maintenance);
	
	countExpenses();
	
	return 0;
}


