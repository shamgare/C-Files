#include <stdio.h>

int main()
{
	int i, j, k, x, kasus, elemen;

	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		int num[200500] = {};
//		for (j = 0; j < 20500; j++) num[j] = 0;
//		memset(num,0,sizeof(num));
		int frek = 0, spasi = 0, aFrek = 0;
		
		scanf("%d", &elemen);
		
		for (j=0;j<elemen;j++) {
			scanf("%d", &x);
			num[x]++;
			
			if (num[x] > frek) {
				frek = num[x];
			}
		}
		
		printf("Case #%d: %d\n", i+1, frek);
		
		for (k=0;k<200500;k++) {
			if (num[k] == frek) {
				aFrek = k;
				if (spasi == 1) {
					printf(" %d", aFrek);
				} else {
					printf("%d", aFrek);
					spasi = 1;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
