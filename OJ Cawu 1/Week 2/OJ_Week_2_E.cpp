#include <stdio.h>

int main()
{
	int n, j, l, b, i, sum = 0, avg;
	scanf("%d", &n);
	
	int p[n];
	
	scanf("%d %d %d", &j, &l, &b);
	
	for (i=0;i<n;i++) {
		scanf("%d", &p[i]);
		sum = sum + p[i];
	}
	
	avg = (j+l+b+sum) / (n+3);
	
	if (j >= avg) {
		printf("Jojo lolos\n");
	} else {
		printf("Jojo tidak lolos\n");
	}
	
	if (l >= avg) {
		printf("Lili lolos\n");
	} else {
		printf("Lili tidak lolos\n");
	}
	
	if (b >= avg) {
		printf("Bibi lolos\n");
	} else {
		printf("Bibi tidak lolos\n");
	}
	
	return 0;
}
