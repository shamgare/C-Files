#include <stdio.h>

int main()
{
	int max, min, num;
	
	scanf("%d", &num);
	min = num;
	max = num;
	
	while (num != -99) {
		
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
		scanf("%d", &num);
	}
	
	printf("%d is the largest number\n", max);
	printf("%d is the smallest number\n", min);
}
