#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int age;
	float ipk;
	int d;
	char nama[69];
	
	{
		
		printf ("Ketik umur anda: ");
		scanf ("%d", &age);
		printf ("Ketik ipk anda: ");
		scanf ("%f", &ipk); 
		getchar();
		printf ("Ketik nama anda: ");
		//scanf("%i", &d);		   //perlu getchar
		scanf ("%[^\n]", &nama); //perlu getchar
		//fgets (nama, 69, stdin); //perlu getchar
		//scanf ("\n%[^\n]", &nama); 
	}
	
	printf ("Umur anda adalah %d tahun\n", age);
	printf ("Ipk anda adalah %.1f\n", ipk); 
	printf ("Nama anda adalah %s\n", nama); 
	//printf ("Nama anda adalah %i\n", d); 
	
}
