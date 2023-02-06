#include <stdio.h>

void test();
int main()
{
	/* char nama[14] = "shamgar";
	printf ("%s\n", nama); 
	char nama[17];
	scanf ("%s", &nama);
	printf ("Nama anda adalah: %s", nama); */
	
	// int a, b, c, x, hasil;
	// a = 1;
	// b = 3;
	// c = -2;
	// x = b;
	// hasil = a*x*x + b*x + c;
	// printf("ax^2 + bx + c = %d\n", hasil);
	test();
}

// 1. tentuin tipe data dari variable nya
// 2. int main
// 3. masukkan nilai variable nya
// 4. printf ("nilai = %?\n", variable)
// 5. hasilnya adalah nilai = (nilai variable yang ditulis)

void test()
{
	// int a, b, c, d;
	// a = 2, b = 3, c = 1;
	// a = a-b;
	// b = b-c;
	// d = abs(a-b);.
	char str[1000] = {};
	int n = 3;
	for (int i = 0; i < n; i++) {
    	printf("%d sheep...", i+1);
  	}
}