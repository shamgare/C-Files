#include <stdio.h>
#include <string.h>
#include <math.h>

int main() 
{
	int i, a[] = {};
//	memset(a,0,sizeof(a));
	for (i=0;i<100;i++) a[i] = 0;
	for (i=0;i<100;i++) printf("%d\n", a[i]);
	return 0;
}
