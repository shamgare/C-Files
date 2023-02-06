#include <stdio.h>

int main()
{
	int kasus, i, a, b;
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++) {
		scanf("%d %d", &a, &b);
		if (a>b) {
			printf("Case #%d: Go-Jo\n", i+1);
		} else {
			printf("Case #%d: Bi-Pay\n", i+1);
		}
	}
	return 0;
}
