#include <stdio.h>

int main()
{
	int a = 5;
	int pointer = 45;
	int *pointr = &a;
	
	printf("adress: %d value: %d", pointer, *pointr);
}

