#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int i;
	char str[10050];
	
	scanf("%[^\n]", str);
	
	for(i=0;i<strlen(str);i++) {
		
		if (islower(str[i]))  {
			str[i] = toupper(str[i]);
		}
		
		if (str[i] == 'I') str[i] = '1';
		if (str[i] == 'R') str[i] = '2';
		if (str[i] == 'E') str[i] = '3';
		if (str[i] == 'A') str[i] = '4';
		if (str[i] == 'S') str[i] = '5';
		if (str[i] == 'G') str[i] = '6';
		if (str[i] == 'T') str[i] = '7';
		if (str[i] == 'B') str[i] = '8';
		if (str[i] == 'P') str[i] = '9';
		if (str[i] == 'O') str[i] = '0';
	}
	
	printf("%s\n", str);
	
	return 0;
}
