#include <stdio.h>
#include <math.h>

int main()
{
	//bitwise operation
	int m = 178, n = 1787, o;
	m = m^n;
	n = m^n;
	m = m^n;
	
	printf("m = %d , n = %d", m, n);
	
	return 0;
}
