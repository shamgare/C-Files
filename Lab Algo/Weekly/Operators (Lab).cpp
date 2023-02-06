#include <stdio.h>

int main()
{
	printf("Operators\n");
	printf("=========\n");
	printf("Input your favorite number: ");
	
	int favNum;
	scanf("%d", &favNum);
	
	int result1, result2, result3;
	result1 = 2*favNum + 3;
	result2 = result1/3 - 4;
	result3 = result2;
	result3 *= result2;
	
	int* y; //deklarasi pointer
	y = &favNum;
	
	printf("Result 1: %d\n", result1);
	printf("Result 2: %d\n", result2);
	printf("Result 3: %d\n", result3);
	printf("%d\n", *y);
	
	if (*y >= 10) {
		printf("Y is bigger or equals 10\n");
	} else {
		printf("Y is smaller than 10\n");
	}
	
	// ternary = printf((kondisi) ? kalo bener : kalo salah)
	printf((*y % 2 == 0) ? "Y is even" : "Y is odd");
	return 0;
}
