#include <stdio.h>

int main()
{
	int kasus, kotak, koin;
	scanf("%d", &kasus);
	
	int i, j, k, max=-1000000, max2=-1000000;
	for (i=0;i<kasus;i++) {
		max=-1000000, max2=-1000000;
		scanf("%d", &kotak);
		for (j=0;j<kotak;j++) {
			scanf("%d", &koin);
			if (koin>max) {
				max2=max;
				max=koin;
			} else if (koin>max2) {
				max2 = koin;
			}
		}
		printf("Case #%d: %d\n", i+1, max+max2);
	}
	
	return 0;
}
