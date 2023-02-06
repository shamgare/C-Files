#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char plural_noun[20];
	char color[20];
	char place[20];
    	{
		    printf ("Enter a plural noun: ");
			scanf("%s", plural_noun);
			printf ("Enter a color: ");
			scanf("%s", color);
			printf ("Enter a place: ");
			getchar();
			scanf("%[^\n]", &place);
		}
	{
		printf("%s are red\n", plural_noun);
		printf("Violets are %s\n", color);
		printf("I want to go to %s\n", place);
	}
	return 0;
}
