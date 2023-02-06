#include <stdio.h>
#include <stdlib.h>

int main()
{
	
//	char nama[71];
//	int angka;
//	angka = 68;
//	
//	printf ("Nama saya adalah %s\n", nama);
//	printf ("Angka favorit saya adalah %d\n", angka);
//	return 0; 
	
	//ATAU
	
	char nama[69];
	scanf ("%s", &nama);
	int angka;
	scanf ("%d", &angka);
	
	printf ("Nama saya adalah %s\n", nama);
	printf ("Angka favorit saya adalah %d\n", angka);
	return 0;
}
