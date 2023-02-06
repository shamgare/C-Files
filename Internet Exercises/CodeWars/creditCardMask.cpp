#include <stdio.h>
#include <string.h>

char* mask(char* str, int len)
{
    int index = 0;

    if (len <= 4) {
        return str;
    } else {
        while (len > 4) {
            str[index] = '#';
            len--;
            index++;
        }
        return str;
    }
}

int main()
{
    char str[255] = {};
    scanf("%[^\n]", str);

    char result[strlen(str)] = {};
    strcpy(result, mask(str, strlen(str)));

    printf("%s\n", result);
}

// resultant = 9
// #####tant = 
// 012345678
// 012345 (strlen - 4)