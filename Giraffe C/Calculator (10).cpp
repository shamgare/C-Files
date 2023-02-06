#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double num1;
	double num2;
	{
		printf ("Calculator Pertambahan\n");
		printf ("Enter a number: ");
		scanf ("%lf", &num1);
		printf ("Enter another number: ");
		scanf ("%lf", &num2);
	}
	double hasil = num1 + num2;
	printf ("Jawabannya adalah %.2lf", hasil);
	return 0;
}
