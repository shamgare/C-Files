#include <stdio.h>
int main()
{
	char id [11];
	char nama[101];
	char kelas;
	char absen[4];
	
	//scanf("%d", &id);
	scanf("%s", &id);
	getchar();
	scanf("%[^\n]", &nama);
	getchar();
	scanf("%c %s", &kelas, &absen);
	
	//printf("Id\t: %d\n", id);
	printf("Id\t: %s\n", id);
	printf("Name\t: %s\n", nama);
	printf("Class\t: %c\n", kelas);
	printf("Num\t: %s\n", absen);
	
	return 0;
}

