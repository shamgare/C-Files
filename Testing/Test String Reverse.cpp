#include <stdio.h>
#include <string.h>

int main()
{
	int kasus, i, j, k;
	int n, m, t;
	
	scanf("%d", &kasus);
	
	for (i=0;i<kasus;i++){
		char str[550] = {};
		char x[550] = {};
		
		scanf("%s", str);
		
		for (j=0;j<strlen(str);j++) {
			x[j] = str[j];
		}
//===============STEP 1==============================		
//		n = 0;
//		m = strlen(str) - 1;
//		while (n<m) {
//			t = x[n];
//			x[n] = x[m];
//			x[m] = t;
//			n++;
//			m--;
//		}
//================STEP 2==============================
		for (k=0;k<strlen(str);k++) {
			x[strlen(str) - 1 - k] = str[k];
		}
//================HASIL====================================
		printf("1.%s %s\n", str, x);
//================CARA NON HALAl==============================
		printf("3.%s %s\n", str, strrev(str));
	}
	return 0;
}
