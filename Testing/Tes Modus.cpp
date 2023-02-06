#include <stdio.h>

int main()
{
	int i, j, k, x, kasus, elemen, num[20500] = {}, frek = 0, aFrek = 0;
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		frek = 0;
		num[20500] = {};
		aFrek = 0;
		
		scanf("%d", &elemen);
		
		for (j=0;j<elemen;j++) {
			scanf("%d", &x);
			num[x]++;
			
			if (num[x] > frek) {
				frek = num[x];
			}
		}
		printf("Case #%d: %d\n", i+1, frek);
		
		for (k=1;k<=elemen;k++) {
			if (num[k] == frek) {
				aFrek = k;
				printf("%d", aFrek);
				if (k!=elemen) {
					printf(" ");
				} else {
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
