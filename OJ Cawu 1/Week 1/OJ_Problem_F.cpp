#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	char plus, equal;
	
	scanf("%d %c %d %c", &a, &plus, &b, &equal);
	scanf("%d %c %d %c", &c, &plus, &d, &equal);
	scanf("%d %c %d %c", &e, &plus, &f, &equal);
	
	printf("%d\n", a+b);
	printf("%d\n", c+d);
	printf("%d\n", e+f);
	
	return 0;
}
