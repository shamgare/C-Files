#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fiboString(int index, char* x, char* y, char* str)
{
    if (index == 0) return x;
    else if (index == 1) return y;

    // return strcat(fiboString(index-1, x, y), fiboString(index-2, x, y));
    // return sprintf(str, "%s%s", fiboString(index-1, x, y, str), fiboString(index-2, x, y, str));
}

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int num;
        char x[50] = {};
        char y[50] = {};

        scanf("%d", &num); getchar();
        scanf("%s %s", x, y);

        char str[255] = {};
        strcpy(str, fiboString(num, x, y, str));

        printf("Case #%d: %s\n", i+1, str);
    }
    return 0;
}