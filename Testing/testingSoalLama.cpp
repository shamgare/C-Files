#include <stdio.h>
#include <string.h>

void polafor()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i; j++) {
			for (int k = j; k < i+j+1; k++) {
				printf("*");
			}
			printf("\n");
		}
 	}
}

void tesalgocheck()
{
	int kasus; scanf("%d", &kasus);
	char arr[20][220] = {}; int count = 0; char str[220] = {};
	for (int i = 0; i < kasus; i++) {
		scanf("%s", &str);
		int check = 0;
		for (int j = 0; j < count; j++) {
			if (strcmp(str, arr[j]) == 0) check = 69;
		}
		if (check == 0) { strcpy(arr[count], str); count++;}
	}
	printf("%d\n", count);
}

void sub()
{
	char str[200] = {}; scanf("%s", str);
	int len = strlen(str);

	char arr[20][200] = {};
	for (int i = 0; i < len; i++) {
		
	}
}

int main()
{
	//tesalgocheck();
	sub();
	return 0;
}


