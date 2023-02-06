#include <stdio.h>

int main()
{
	long int d, s, t; 
	scanf("%ld %ld %ld", &d, &s, &t);

	if (d>s && d>t && s>t) {
		printf("Daging\n");
		printf("Sayur\n");
		printf("Telur");	
	} else if (d>s && d>t && t>s) {
		printf("Daging\n");
		printf("Telur\n");
		printf("Sayur\n");
	} else if (t>s && t>d && s>d) {
		printf("Telur\n");
		printf("Sayur\n");
		printf("Daging\n");
	} else if (t>s && t>d && d>s) {
		printf("Telur\n");
		printf("Daging\n");
		printf("Sayur\n");
	} else if (s>d && s>t && t>d) {
		printf("Sayur\n");
		printf("Telur\n");
		printf("Daging\n");
	} else /* if (s>d && s>t && d>t) */ {
		printf("Sayur\n");
		printf("Daging\n");
		printf("Telur\n");
	}
	
	return 0;
}
