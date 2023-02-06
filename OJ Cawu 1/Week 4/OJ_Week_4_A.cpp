#include <stdio.h>
#include <string.h>

int main()
{
	int kasus, i, j, k, l, n = 0, m, t = 0;
	char str[1050], x[1050], y[1050];
	scanf("%d", &kasus);
	getchar();
	
	for (i=0;i<kasus;i++) {
		scanf("%s", str);
		n = 0, t = 0;
		for (j=0;j<strlen(str);j++) {
			x[j] = str[j];
		}
		
		m = strlen(str);
		
		while (n<m) {
			t = x[n];
			x[n] = x[m];
			x[m] = t;
			n++;
			m--;
		}
		
		printf("Case %d: ", i+1);
		
		for (k=1;k<strlen(str)+1;k++) {
			y[k] = x[k] % 2;
			printf("%d", y[k]);
		}
		printf("\n");
	}
	return 0;
}
