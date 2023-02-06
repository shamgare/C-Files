#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c)
{
	int hasil;
	if(a <= b && a <= c){
		hasil = a;
	} else if(b <= a && b <= c){
		hasil = b;
	} else {
		hasil = c;
	}
	return hasil;
}

int main()
{
	printf("%d\n", min(11,12,14));
	
	if ((2 > 4) ^ (2 != 2)){      // || or, && and, == equals, ^ x or
		printf("True");
	} else {
		printf("False");
	}
	return 0;
}

//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	if(x >= y){
//		printf("Hasil = %d\n", x);
//	} else {
//		printf("Hasil = %d\n", y);
//	}
//	return 0;
//}
