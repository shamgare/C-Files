#include <stdio.h>

int main()
{
	int kasus, i, j, k, n, count;
	long long int angka[10050], hasil[10050];
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		scanf("%d", &n);
		
		count = 0;
		angka[10050] = {};
		hasil[10050] = {};
		
		for (j=0;j<n;j++) {
			scanf("%lld", &angka[j]);
		}
		for (k=0;k<n;k++) {
			scanf("%lld", &hasil[k]);
			if (angka[k] < hasil[k]) {
				count++;
			}
		}
		printf("Case #%d: %d\n", i+1, count);
	}
	return 0;
}
