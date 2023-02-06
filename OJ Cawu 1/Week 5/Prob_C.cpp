#include <stdio.h>
#include <string.h>

int main()
{
	char str[10050];
	
	scanf("%[^\n]", str);

	for (int i = 0;i<strlen(str);i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str [i] = str[i] + 32;
        }
        if (str[i] == '1') str[i] = 'i';
		if (str[i] == '2') str[i] = 'r';
		if (str[i] == '3') str[i] = 'e';
		if (str[i] == '4') str[i] = 'a';
		if (str[i] == '5') str[i] = 's';
		if (str[i] == '6') str[i] = 'g';
		if (str[i] == '7') str[i] = 't';
		if (str[i] == '8') str[i] = 'b';
		if (str[i] == '9') str[i] = 'p';
		if (str[i] == '0') str[i] = 'o';
    }

    printf("%s\n", str);
	return 0;
}