#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Products {
	char name[255];
	int price;
    char review[255];
} p1[10];

int main()
{
	FILE* file = fopen("products.txt", "r");
	int lastIndex = 0;
	
	while (!feof(file)) {
		fscanf(file, "%[^#]#%d#%[^\n]\n", p1[lastIndex].name, &p1[lastIndex].price, p1[lastIndex].review);
		printf("%s \nRp.%d \n%s\n", p1[lastIndex].name, p1[lastIndex].price, p1[lastIndex].review);
		lastIndex++;
	}
	
	fclose(file);
	
	file = fopen("products2.txt", "w");

	strcpy(p1[lastIndex].name, "Kuda");
	p1[lastIndex].price = 69000;
    strcpy(p1[lastIndex].review, "Lezat");
	lastIndex++;
	
	for(int i = 0; i < lastIndex; i++) {
		fprintf(file,"%s#%d#%s\n", p1[i].name, p1[i].price, p1[i].review);
	}
	fclose(file);
}