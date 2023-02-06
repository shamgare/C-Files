#include <stdio.h>

int stringLength(char*);
void reverse(char*, int, int);
void swap (char*, char*);

int main()
{
    char str[255] = {};
    scanf("%s", str);

    reverse(str, 0, stringLength(str)-1);
    printf("%s\n", str);
}

















int stringLength(char* str) 
{
    if (*str != '\0') {
        return 1 + stringLength(str + 1);
    }
    return 0;
}

void swap(char* x, char* y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(char* str, int a, int len)
{
    if (a < len) {
        swap(&str[a], &str[len]);
        reverse(str, a + 1, len - 1);
    }
}