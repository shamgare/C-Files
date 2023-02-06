#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b;
    int x, y;
    int max;
    scanf("%d %d", &a, &b);

    char str[a] = {};
    scanf("%s", str);

    char str2[255] = {};
    strcpy(str2, str);

    int len = strlen(str) - 1;
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[len];
        str2[len] = str2[i];
        len--;


        for (int j = 0; j < b; j++) {
            // if (str[i] != 9) {
            //     str[i] = '9';
            // }
            // if (str2[i] != 9) {
            //     str2[i] = '9';
            // }
        }
    }
    
    x = atoi(str);
    y = atoi(str2);
    max = x;
    if (y > x) max = y;

    printf("%d\n", max);
}