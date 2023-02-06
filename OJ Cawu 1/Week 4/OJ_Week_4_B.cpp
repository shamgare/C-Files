#include <stdio.h>
#include <string.h>

int main()
{
	int kasus, i, j, k, a = 0;
	char str[1050], x[1050];
	scanf("%d", &kasus);
	getchar();
	
	for (i=0;i<kasus;i++) {
		scanf("%s", str);
		a = 0;
		
		for (j=0;j<strlen(str);j++) {
			x[j] = str[j];
		}

		printf("Case %d: ", i+1);
		
		for (k=1;k<=strlen(str);k++) {
			printf("%d", x[k-1]);
			if (k != strlen(str)) {
				printf("-");
			} else {
				printf("\n");
			}
		}
	}
	return 0;
}
