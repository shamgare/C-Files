#include <stdio.h>
#include <string.h>

int main()
{
	int kasus, i, j, k, l;
	int n = 0, m, t;
	scanf("%d", &kasus);
	getchar();
	
	for (i=0;i<kasus;i++){
		char str[550] = {};
		char x[550] = {};
		int a;
		scanf("%s", str);
		
		for (j=0;j<strlen(str);j++) {
			x[j] = str[j];
		}
		
		n = 0;
		m = strlen(str) - 1;
		
		while (n<m) {
			t = x[n];
			x[n] = x[m];
			x[m] = t;
			n++;
			m--;
		}
		
		a = strcmp (str,x);
		printf("%d", a);
		for (k=0;k<strlen(str);k++) printf("%s %s\n", str, x);
		
		if (a==0) {
			printf("Case #%d: Yay, it's a palindrome\n", i+1);
		} else {
			printf("Case #%d: Nah, it's not a palindrome\n", i+1);
		}
	}
	return 0;
}
