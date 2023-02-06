#include <stdio.h>

int main ()
{
	int a = 0, b, i;
	
	printf("Enter a limit number: ");
	scanf("%d", &b);
	
	for (i=0;a<=b;) {
	//	printf("%d ", a);
		a = a + 2;
		++i;
	}
	printf("Even numbers: %d", i);
}
