#include <stdio.h>

int main()
{
	int kasus, n, i, j;
	long long int num, sum;
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		sum = 0;
		num = 0;
		scanf("%d", &n);
		
		for (j=0;j<n;j++) {
			scanf("%lld", &num);
			sum += num;
		}
		printf("Case #%d: %lld\n", i+1, sum);
	}
	return 0;
}
