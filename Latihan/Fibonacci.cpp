#include <stdio.h>

int main()
{
	int a, b, sum, input;
	a = 0;
	b = 1;
	sum = a + b;
	
	printf("Enter an integer: ");
	scanf("%d", &input);
	printf("Fibonacci : %d ", b);

	while (sum <= input) {
		printf("%d ", sum);
		a = b;
		b = sum;
		sum = a + b;
	}
	return 0;
}
