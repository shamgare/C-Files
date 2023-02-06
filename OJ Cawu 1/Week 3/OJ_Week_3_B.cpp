#include <stdio.h>

int main()
{
	int array[1050] = {}, jumlah, urutan[1050] = {};
	int i,j,k;
	
	scanf("%d", &jumlah);
	
	for (i=0;i<jumlah;i++) {
		scanf("%d", &urutan[i]);
	}
	
	for (j=0;j<jumlah;j++) {
		scanf("%d", &array[urutan[j]]);
	}
	
	for (k=0;k<jumlah;k++) {
		printf("%d", array[k]);
		if (k+1 != jumlah) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	
	return 0;
}
