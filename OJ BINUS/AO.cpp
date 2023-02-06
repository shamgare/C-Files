#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int a;
        scanf("%d", &a); getchar();

        char str[a] = {};
        scanf("%[^\n]", str);

        int len = strlen(str);
        char str2[a] = {};
        int k = 0;
        for (int j = 0; j < len; j++) {
            if (str[j] >= 97 && str[j] <= 122) {
                str2[k] = str[j];
                k++;
            }
        }
        printf("Case #%d: %s\n", i+1, str2);
    }
    return 0;
}