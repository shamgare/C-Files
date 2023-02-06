#include <stdio.h>

int main()
{
	int angka;
	
	printf("Masukkan angka anda: ");
	scanf("%d", &angka);
	
	switch (angka){
	case 1:
		printf("Selamat! Anda peringkat pertama!");
		break;
	case 2:
		printf("Anda peringkat kedua!");
		break;
	case 3:
		printf("Anda peringkat ketiga!");
		break;
	case 4:
		printf("Anda peringkat keempat!");
		break;
	default:
		printf("Angka Invalid");
	}
	return 0;
}
