#include <stdio.h>

int main()
{
	int i, j, k, l = 0, kasus, elemen, num[2050] = {};
	long long int sum = 0;
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		scanf("%d", &elemen);
		sum = 0;
		l = 0;
		
		for (j=0;j<elemen;j++) {
			scanf("%d", &num[j]);
			sum += num[j];
		}
		
		for (k=0;k<elemen;k++) {
			if (num[k]>sum) {
				l++;
			}
		}
		printf("Case #%d: %lld\n", i+1, sum);
		printf("%d\n", l);
	}
	return 0;
}
