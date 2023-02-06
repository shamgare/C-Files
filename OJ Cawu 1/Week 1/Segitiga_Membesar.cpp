#include <stdio.h>

int main()
{
	int i, n, j;
	scanf("%d", &n);
	
	if (n%2==0) {
		for (i=1;i<=n;i++) {
				for (j=n;j>0;j--) {
					if (j > i) {
			       		printf(" ");
			       	} else {
				      	if (i%2==0) {
				          	j%2!=0 ? (printf("*")) : (printf("#"));
						} else {
							j%2!=0 ? (printf("#")) : (printf("*"));
						}
			       	}
				}
			printf("\n");
		}	
	} else {
		for (i=1;i<=n;i++) {
				for (j=n;j>0;j--) {
					if (j > i) {
			       		printf(" ");
			       	} else {
				      	if (i%2==0) {
				          	j%2!=0 ? (printf("#")) : (printf("*"));
						} else {
							j%2!=0 ? (printf("*")) : (printf("#"));
						}
			       	}
				}
			printf("\n");
		}
	}
}
