#include <stdio.h>
#include <string.h>

int main()
{
	char primary1[255];
	char primary2[255];
	
	printf("Enter a primary color: ");
	scanf("%s", primary1); 
	printf("Enter another primary color: ");
	scanf("%s", primary2);
	
	if (primary1 =="Red" && primary2=="Blue") {
		printf("Your secondary color is Purple");
	} else {
		printf("Error");
	}
}
