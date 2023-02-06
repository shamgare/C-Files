#include <stdio.h>

int main()
{
	int a, b, i, j;
	scanf("%d %d", &a, &b);
	
	for (i=0;i<a;i++) {
		for (j=0;j<a;j++) {
			printf("#");
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (int i=1;i<=a;i++) {
		for (j=0;j<a;j++) {
			if (i%b==0) {
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (int i=0;i<a;i++) {
		for (j=1;j<=a;j++) {
			if (j%b==0) {
				printf("#");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
