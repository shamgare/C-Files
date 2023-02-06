#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n, m, i, x;
	char arr[250];
	scanf("%d %d", &n, &m);
	scanf("%s", arr);
	
	for (i=0;i<m;i++) {
		scanf("%d", &x);
		//a = isupper(arr[x]);
		//a == 1
		if (isupper(arr[x])) {
			arr[x] = tolower(arr[x]);
		} else {
			arr[x] = toupper(arr[x]);
		}
	}
	
	printf("%s\n", arr);
	
	return 0;
}
