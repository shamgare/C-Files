#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);
    getchar();
    char str[100];

    for (int i = 0; i < kasus; i++) {
        scanf("%s", str);

        int r = strlen(str) - 1;
        for (int j = 0; j<strlen(str); j++) {
            str[r--] = str[j];
        }
        printf("Case #%d: %s\n",i+1, str);
    }
    return 0;
}