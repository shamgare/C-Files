#include <stdio.h>

int main()
{
	int totalDays;
	int d;
	int w;
	int y;
	
	scanf("%d", &totalDays);
	y = totalDays / 365 ;
	w = (totalDays % 365) / 7;
	d = totalDays % ((y*365) + (w * 7));
	
	printf("Years: %d\n", y);
	printf("Weeks: %d\n", w);
	printf("Days: %d\n", d);
	
	return 0;
}
