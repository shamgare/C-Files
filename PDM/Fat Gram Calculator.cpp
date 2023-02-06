#include <stdio.h>

float fat, cal, percentage;

int calculate(float x, float y) {
	percentage = x * 9 / y;
}

int main()
{
	do {
		printf("Enter the number of fat grams and calories in the food: ");
		scanf("%f %f", &fat, &cal);
	} while (fat<0 || cal<0);
	
	//percentage = fat * 9 / cal;
	calculate(fat,cal);
	
	if (percentage < 0.3) {
		printf("The food is low in fat.\n");
	} else {
		printf("The food is not low in fat.\n");
	}
	
	return 0;
}
