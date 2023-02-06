#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        char str[a] = {};
        scanf("%s", str);

        for (int j = 0; j < strlen(str); j++) {
            str[j] -= 97;
            str[j] += b;
            while (str[j] > 25) {
                str[j] -= 26;
            }
            str[j] += 97;
        }
        printf("Case #%d: %s\n", i+1, str);
    }
    return 0;
}