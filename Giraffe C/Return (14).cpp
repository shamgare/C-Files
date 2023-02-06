#include <stdio.h>
#include <stdlib.h>

double pangkat(double a)
{
	return (a * a * a);
}

char tes(char c[])
{	
	return (printf("hi %s\n", c));
}

int main()
{
	tes("ejije");
	printf("Jawaban: %.2lf", pangkat(3));
	return 0;
}
