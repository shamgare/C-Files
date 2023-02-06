#include <stdio.h>
#include <stdlib.h>


//int angka()
//{
//	int x;
//	int y;
//	x = 6;
//	y = 7;
//	printf("%d", x * y);
//}
//
//int main()
//{
//	angka();
//	return 0;
//}

//ATAU


int angka(int x, int y)
{
	printf("%d\n", x * y);
}

int tes()
{
	printf("Hello\n");	
}

void testi()
{
	char test[123];
	// ga perlu getchar
	//fgets (test, 123, stdin);
	scanf("%[^\n]", &test);
	printf("%s\n", test);
}

void kata(char nama[])
{
	printf("%s\n", nama);
}

void loop()
{
	int x;
	scanf("%d",&x);
	for (int i = 0;i <= x;i++)
		{
			printf("       /\\\n");
			printf("      /  \\\n");
			printf("     /    \\\n");
			printf("    /      \\\n");
			printf("   /        \\\n");
			printf("  /__________\\\n");
			printf("\n");
		}
}

int main()
{
	tes();
	angka(5,6);
	testi();
	kata("Babi");
	kata("Itu");
	kata("Enak");
	kata("Banget");
	kata("Lho");
	loop();
	
	return 0;
}

