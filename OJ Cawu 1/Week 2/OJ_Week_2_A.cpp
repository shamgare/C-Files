#include <stdio.h>

int main()
{
	long int a,b,c,d;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if (a*b == c-d) {
		printf("True\n");
	} else {
		printf("False\n");
	}
	
	return 0;
}
