#include <stdio.h>

int main()
{
    char str[255] = {};
    char temp[255] = {};
    int len = 0;
    int x;
    scanf("%s", str);

    while (str[len] != '\0') len++;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            x = 0;
            for (int k = j; k < i+j+1; k++) {
                temp[x] = str[k];
                x++;
            }
            printf("%s\n", temp);
        }
    }
}