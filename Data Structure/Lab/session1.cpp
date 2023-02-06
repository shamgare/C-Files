#include <stdio.h>

int main()
{
	int a = 1;
	int* p = &a;
	
	printf("%d\n", &a);
	
	a = 2;
	printf("%d\n", *p);
	
	*p = 3;
	printf("%d\n", *p);
	
	int** c = &p;
	int*** d = &c;
	int**** e = &d;
	
	printf("%d\n", **c);
}
