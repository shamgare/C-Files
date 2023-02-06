#include <stdio.h>

int main()
{
	int num = 0, sum = 0;
	
	do { 
		sum = sum + num;
		printf("Enter a number: ");
		scanf("%d", &num);
	} 
	while (num > 0);
	
	printf("%d", sum);
}
