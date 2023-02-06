#include <stdio.h>
#include <string.h>

void rev(), makepal(), check();
void mod(), matrix(), evenSum();
void maxChoc(), mBox(), anagram(), depo();

int main()
{
	//rev();
	//makepal();
	//check();
	//mod();
	//matrix();
	//evenSum();
	//maxChoc();
	//mBox();
	//anagram();
	depo();
    return 0;
}

void rev()
{
	char str[1000];
	char str2[1000];
	int len = 0;
	scanf("%s", str);
	
	while (str[len] !='\0') len++;
	
	int x = len-1;
	for (int i = 0; i < len; i++) {
		str2[i] = str[x];
		x--;
	}
	
	printf("%s\n", str2);
}

void makepal()
{
	char str[100];
	scanf("%s", str);
	
	int len = 0;
	while (str[len] != '\0') len++;
	
	int x = len-1;
	for (int i = 0; i < len; i++) {
		str[x] = str[i];
		x--;
	}
	printf("%s\n", str);
}

void check()
{
	char str[100];
	scanf("%s", str);
	int len = 0;
	while (str[len] != '\0') len++;
	
	int x = len -1;
	int count = 0;
	for (int i = 0; i < x; i++) {
		if (str[i] != str[x]) {
			count++;
		}
		x--;
	}
	
	if (count > 0) {
		printf("Not a palindrome\n");
	} else {
		printf("Palindrome\n");
	}
}

void mod()
{
	int kasus;
	scanf("%d", &kasus);
	
	int angka1, angka2;
	int angkaT, hasil = 0, j=1;
	
	for (int i = 0; i < kasus; i++) {
		scanf("%d %d", &angka1, &angka2);
		hasil = 0;
		j = 1;
		while (angka1 != 0 || angka2 != 0) {
			angkaT = (angka1 % 10) + (angka2 % 10);
			angkaT %= 10;
			hasil += (angkaT*j);
			j*=10;
			angka1 /= 10;
			angka2 /= 10;
		}
		printf("%d\n", hasil);
	}
}

void matrix()
{
	int matriks1[255][255];
	int matriks2[255][255];
	int hasil[255][255] = {};
	int a, b, c, d;
	
	do {
		printf("Ukuran matriks pertama: ");
		scanf("%d %d", &a, &b);
		printf("Ukuran matriks kedua: ");
		scanf("%d %d", &c, &d);
		if (b != c) printf("Masukkin angka yang bener...\n");
	} while (b != c);
	
	printf("Angka matriks %d x %d:\n", a,b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &matriks1[i][j]);
		}
	}
	printf("Angka matriks %d x %d:\n", c,d);
	for (int k = 0; k < c; k++) {
		for (int l = 0; l < d; l++) {
			scanf("%d", &matriks2[k][l]);
		}
	}
	
	printf("Hasil dari perkalian matriks:\n");
	
	int spasi = 0;
	for(int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			for (int k = 0; k < b; k++) {
				hasil[i][j] += matriks1[i][k]*matriks2[k][j];
			}
		}
	}
	
	for(int i = 0; i < a; i++) {
		spasi = 0;
		for (int j = 0; j < d; j++) {
			if (spasi == 0) {
			 printf("%d", hasil[i][j]);
			 spasi++;
			} else {
				printf(" %d", hasil[i][j]);
			}
		}
		printf("\n");
	}
}

void evenSum()
{
	int kasus;
	scanf("%d", &kasus);
	
	int angka;
	int sum;
	int min;
	int arr[255] = {};
	
	for (int i = 0; i < kasus; i++) {
		scanf("%d", &angka);
		sum = 0;
		min = 100000000;
		
		for (int j = 0; j < angka; j++) {
			scanf("%d", &arr[j]);
			if (arr[j]<min && arr[j]%2 != 0) {
				min = arr[j];
			}
			sum += arr[j];
		}
		
		if (sum%2==0) {
			printf("Case #%d: %d\n", i+1, sum);
		} else {
			printf("Case #%d: %d\n", i+1, sum-min);
		}
	}
}

void maxChoc()
{
	int kasus;
	scanf("%d", &kasus);
	
	int jumlah;
	int arr[255] = {};
	int max;
	for (int i = 0; i < kasus; i++) {
		max = 0;
		scanf("%d", &jumlah);
		for (int j = 0; j < jumlah; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] > max) {
				max = arr[j];
			}
		}
		int spasi = 0;
		printf("Case #%d: ", i+1);
		for (int k = 0; k < jumlah; k++) {
			arr[k] = max;
			if (spasi == 0) {
				printf("%d", arr[k]);
				spasi++;
			} else {
				printf(" %d", arr[k]);
			}
		}
		printf("\n");
	}
}

void mBox()
{
	int kasus;
	scanf("%d", &kasus);
	
	int angka;
	int arr[255] = {};
	int max1, max2, max3;
	int temp;
	for (int i = 0; i < kasus; i++) {
		max1 = 0, max2 = 0, max3 = 0;
		scanf("%d", &angka);
		
		for (int j = 0; j < angka; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] > max3) max3 = arr[j];
		}
		for (int k = 0; k < angka; k++) {
			if (arr[k] > max2 && arr[k] < max3) max2 = arr[k];
		}
		for (int l = 0; l < angka; l++) {
			if (arr[l] > max1 && arr[l] < max2) max1 = arr[l];
		}
		printf("Case #%d: %d %d %d\n", i+1, max1, max2, max3);
	}
}

void anagram()
{
	int kasus;
	scanf("%d", &kasus);
	
	char str[10005];
	char str2[10005];
	int len, x;
	
	for (int i = 0; i < kasus; i++) {
		scanf("%s %s", str, str2);
		x = 0;
		
		if (strlen(str) != strlen(str2)) break;
		len = strlen(str);
		char temp;
		for (int j = 0; j < len-1; j++) {
			for (int k = j+1; k < len; k++) {
				if (str[j] > str[k]) {
					temp = str[j];
					str[j] = str[k];
					str[k] = temp;
				}
				if (str2[j] > str2[k]) {
					temp = str2[j];
					str2[j] = str2[k];
					str2[k] = temp;
				}
			}
		}
		
		for (int i = 0; i < len; i++) {
			if (str[i] != str2[i]) {
				x++;
			}
		}
		
		printf("%s\n", str);
		printf("%s\n", str2);
		if (x > 0) {
			printf("It's Not an anagram\n");
		} else {
			printf("It's an anagram\n");
		}
	}
}

void depo()
{
	long long int n, mny, in;
	scanf("%lld %lld", &n, &mny);

	for (int i = 0; i < n; i++) {
		long long int a = 0, b = 0;
		scanf("%lld %lld", &a, &b);
		in =(mny*a)/100*b/12;
		mny += in;
	}
		printf("%lld", mny);

}
