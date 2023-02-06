#include <stdio.h>

int main()
{
	int kasus, i, j, k, l, x, spasi;
	long long arr[101][101], sum[101];
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		scanf("%d", &x);
		
		for (j=0;j<102;j++) sum[j] = 0;
		arr[101][101] = {};
		spasi = 0;
		
		for (int j=0;j<x;j++) {
			for (k=0;k<x;k++) {
				scanf("%lld", &arr[j][k]);
			}
		}
		
		for (k=0;k<x;k++) {
			for (l=0;l<x;l++) {
				sum[k] += arr[l][k];
			}
		}
		
		printf("Case #%d: ", i+1);
		
		for (j=0;j<x;j++) {
			if (spasi==1) {
				printf(" %lld", sum[j]);
			} else {
				printf("%lld", sum[j]);
				spasi = 1;
			}
		}
		printf("\n");
	}
	return 0;
}
