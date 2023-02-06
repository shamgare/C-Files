#include <stdio.h>

//arithmetic assignment logical relational pointer bitwise operator//

int main()
{
//	printf("Simple Input Output Program\n");
//	printf("===========================\n");
//	printf("Welcome to algorithm and programming.\n");
	char name[255];
	printf("Enter your name: ");
	scanf("%[^\n]", name);
	
	int num;
	printf("Input your age: ");
	scanf("%d", &num);
	//getchar();
	printf("Hi %s\n", name);
	printf("Your age is %d", num);
	return 0;
}
