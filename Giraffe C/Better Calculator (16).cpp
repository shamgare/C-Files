#include <stdio.h>
#include <stdlib.h>

int main()
{
	double a;
	double b;
	char op;
	
	printf("Enter a number: ");
	scanf("%lf", &a);
	printf("Enter an operator: ");
	scanf(" %c", &op);
	printf("Enter another number: ");
	scanf("%lf", &b);
	
	if (op == '+'){
		printf("%.2lf", a + b);
	} else if (op == '-'){
		printf("%.2lf", a - b);
	} else if (op == '*'){
		printf("%.2lf", a * b);
	} else if (op == '/'){
		printf("%.2lf", a / b);
	} else {
		printf("Invalid Operator");
	}
	
	return 0;
}
