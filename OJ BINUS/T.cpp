#include <stdio.h>

int main()
{
    char code[5][255] = {};
    int a[5] = {}, b[5] = {}, c[5] = {}, d[5] = {};
    char temp;

    for (int i = 0; i < 5; i++) {
        scanf("%s", code[i]);
        scanf("%d %c %d %c %d %c %d", &a[i], &temp, &b[i], &temp, &c[i], &temp, &d[i]);
        a[i] -= 1;
        c[i] -= 1;
    }
    for (int i = 0; i < 5; i++) {
        printf("%s %02d:%02d-%02d:%02d\n", code[i], a[i], b[i], c[i], d[i]);
    }
}