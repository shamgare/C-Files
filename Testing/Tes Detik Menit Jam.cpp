#include <stdio.h>

int main()
{
	int detik, menit, jam;
	
	scanf("%d", &detik);
	jam = detik / 3600;
	menit = (detik % 3600) / 60;
	
	printf("%d jam, %d menit", jam, menit);
	
	return 0;
}
