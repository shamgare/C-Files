#include <stdio.h>

int main()
{
	int n, q, i, j, sum = 0, hariA, hariB;
	scanf("%d", &n);
	
	int x[n+50];
	
	for (i=0;i<n;i++) {
		scanf("%d", &x[i]);
	}
	
	scanf("%d", &q);
	
	for (i=0;i<q;i++) {
		sum=0;
		scanf("%d %d", &hariA, &hariB);
		hariA--;
		
		for (j=hariA; j<hariB; j++) {
			sum += x[j];
		}
		printf("Case #%d: %d\n", i+1, sum);
	}
	
	return 0;
}
