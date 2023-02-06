#include <stdio.h>
#include <string.h>

int main()
{
	int kasus;
	char a[105] = {};
	int b[10005] = {};
	int sum = 0;
	
	scanf("%d", &kasus);
	for (int i = 0; i < kasus; i++) {
		sum = 0;
		for (int k = 0; k < 1000; k++) b[k] = 0;
		//b[1000] = {};
		scanf("%s", a);
		
		for (int j = 0; j < strlen(a); j++) {
			b[a[j]-'a']++;	
		}
		for (int k = 0; k < 26; k++) {
			if (b[k] >= 1) sum++;
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
