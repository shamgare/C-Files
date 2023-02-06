#include <stdio.h>

int main()
{
	int a, b, c, d, i;
	a = 0;
	b = 1;
	c = a + b;
	// kalau pake while loop yg berapa angka fibonacci
	i = 1;
	
	printf("Enter an integer: ");
	scanf("%d", &d);
	
	printf("Fibonacci : %d ", b);
	
	// kalau input user = berapa angka fibonacci
	// for (i=3;i<=d;i++) {
	
	// kalau input user = nilai max fibonacci
	// while (c <= d) {
	
	//kalau input user = berapa angka fibonacci
	while (i < d) {
	
	// kalau input user = nilai max fibonacci
	// for (i=0;i<=d;) {
		
		printf("%d ", c);
		a = b;
		b = c;
		c = a + b;
	// hanya untuk while loop
		++i;
	// hanya utk for loop = nilai max fibonacci
	//	i = c;
	}
}
