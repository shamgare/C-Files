#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	const int NUM1 = 5;
	//const = absolute (tidak bisa diubah kedepannya, jadi fix NUM1 = 5. forever.)
	// kata biasa jg const misal : "Hello" atau "90", karena gabisa diubah kecuali diketik.
	double num2 = 4.7;
	double hasil = (NUM1 * num2);
	printf ("hasil = %.1lf\n", hasil);
	printf ("%.1f\n", pow(4,4));
	printf ("%.1f\n", sqrt(81));
	printf ("%.1f\n", ceil(81.12));
	printf ("%.1f\n", floor(81.98));
	printf ("%d\n", 17%6);
	//NUM1 = 6; (tes const)
	printf ("%d", NUM1);
}
