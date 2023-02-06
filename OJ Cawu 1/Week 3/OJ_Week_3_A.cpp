#include <stdio.h>

int main()
{
	int a, b, i, j, perubahan;
	scanf("%d %d", &a, &b);
	
	int kotak[a][b];
	for (i=0;i<a;i++) {
		for (j=0;j<b;j++) {
			scanf("%d", &kotak[i][j]);
		}
	}
	
	scanf("%d", &perubahan);
	
	int x, y, z, k, l, m;
	
	for (k=0;k<perubahan;k++) {
		scanf("%d %d %d", &x, &y, &z);
		kotak[x-1][y-1] = z;
	}
		
	for (l=0;l<a;l++) {
		for (m=0;m<b;m++) {
			printf("%d", kotak[l][m]);
			if (m+1 != b) {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
