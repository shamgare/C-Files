#include <stdio.h>

int main()
{
	int num, max, min, i;
	max = 0;
	min = num;
	
	for (i=0;i<5;i++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
	}
	
	printf("Max is %d\n", max);
	printf("Min is %d", min);
}
