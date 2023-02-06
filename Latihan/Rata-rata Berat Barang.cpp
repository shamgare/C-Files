#include <stdio.h>

int main()
{
	float barang1;
	float barang2;
	float berat1;
	float berat2;
	float avg;
	
	scanf("%f %f %f %f", &barang1, &barang2, &berat1, &berat2);
	
	avg = ((barang1 * berat1) + (barang2 * berat2)) / (barang1 + barang2);
	
	printf("Berat barang 1: %.2f\n", berat1);
	printf("Jumlah barang 1: %.0f\n", barang1);
	printf("Berat barang 2: %.2f\n", berat2);
	printf("Jumlah barang 2: %.0f\n", barang2);
	printf("Rata-rata berat kedua benda: %f\n", avg);
	
	return 0;
}
