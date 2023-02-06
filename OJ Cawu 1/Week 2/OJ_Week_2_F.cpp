#include <stdio.h>

int main()
{
	int i, j, t, x, n;
	scanf("%d", &t);
	
	for (x=0;x<t;x++) {
		
		scanf("%d", &n);
		printf("Case #%d:\n", x+1);
		
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
	return 0;
}

