#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        char str[1050] = {};
        char rev[1050] = {};
        scanf("%s", str);

        for (int k = 0; k < strlen(str); k++) {
            if (str[k] >= 65 && str[k] <= 90) {
                str[k] = str[k] + 32;
            } else {
                str[k] = str[k] - 32;
            }
        }

        for (int j = 0; j < strlen(str); j++) {
            rev[j] = str[strlen(str)-j-1];
        }

        printf("Case #%d: %s\n", i+1, rev);
    }
    return 0;
}