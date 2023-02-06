#include <stdio.h>
#include <string.h>

int main()
{
	char primary1[7];
	char primary2[7];
	
	printf("Enter a primary color: "); getchar();
	scanf("%c", &primary1[0]); 
	
	printf("Enter another primary color: ");
	scanf("%c", &primary2[0]);
	
	if ((primary1[0] == 'R') && (primary2[0] == 'B')) {
		printf("Your secondary color is Purple");
	} else if ((primary1[0] == 'R') && (primary2[0] == 'Y')) {
		printf("Your secondary color is Orange");
	} else if ((primary1[0] == 'B') && (primary2[0] == 'Y')) {
		printf("Your secondary color is Green");
	} else if ((primary1[0] == 'B') && (primary2[0] == 'R')) {
		printf("Your secondary color is Purple");
	} else if ((primary1[0] == 'Y') && (primary2[0] == 'R')) {
		printf("Your secondary color is Orange");
	} else if ((primary1[0] == 'Y') && (primary2[0] == 'B')) {
		printf("Your secondary color is Green");
	} else {
		printf("Error");
	}
	
	return  0;
}
