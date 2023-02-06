#include <cstdio>

int main() 
{
	printf("%d\n", 2 > 1);
	printf("%d\n", 2 < 1);
	printf("%d\n", 2 == 1);
	printf("%d\n", 2 >= 1);
	printf("%d\n", 1 == 1);
	printf("%d\n", 1 != 1);
	printf("%d\n", 1 != 2);
	printf("\n");
	printf("%d\n", 'a'> 'A');
	printf("%d\n", 'a' < 'A');
	printf("%d\n", 'a' >= 'A');
	printf("%d\n", 'a' == 'A');
	printf("%d\n", "a" < "aa");
	printf("%d\n", "abcb" > "abca");
	printf("%d\n", "abc" == "abc");
	printf("%d\n", "abc" <= "abc");
	printf("%d\n", !(2 > 1));
	printf("%d\n", (2 > 1) && (3 > 1));
	printf("%d\n", ((2 > 1) || (3 < 1)) && (1 == 1));
}
