#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        char str[105] = {};
        scanf("%s", str);

        int count = 0;
        for (int j = 0; j < strlen(str); j++) {
            // strlen harus 11
            if (strlen(str) != 11) {
                count = 1;
                break;
            }

            // index pertama hrs angka
            if (str[0] == '.') {
                count = 1;
                break;
            }

            if (j % 2 == 0) {
                // genap harus angka
                if (str[j] >= '0' && str[j] <= '9') {
                    count = 0;
                } else {
                    count = 1;
                    break;
                }
            } else {
                // ganjil harus '.'
                if (str[j] == '.') {
                    count = 0;
                } else {
                    count = 1;
                    break;
                }
            }
        }

        if (count > 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}