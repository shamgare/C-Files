#include <stdio.h>
#include <string.h>

int main()
{
    int kasus;
    char str[1050];
    int angka[1050] = {};

    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%s", str);
        for (int k = 0; k<strlen(str); k++) {
            if (str[k] == 'A' || str[k] == 'I' || str[k] == 'U' || str[k] == 'E' || str[k] == 'O') {
                angka[k] = 0;
            }
            if (str[k] >= 66 && str[k] <= 68) {
                angka[k] = str[k] - 65;
            }
            if (str[k] >= 70 && str[k] <= 72) {
                angka[k] = str[k] - 69;
            }
            if (str[k] >= 74 && str[k] <= 78) {
                angka[k] = str[k] - 73;
            }
            if (str[k] >= 80 && str[k] <= 84) {
                angka[k] = str[k] - 79;
            }
            if (str[k] >= 86 && str[k] <= 90) {
                angka[k] = str[k] - 85;
            }
            if (str[k] == 'B' || str[k] == 'C' || str[k] == 'D') str[k] = 'A';
            if (str[k] == 'F' || str[k] == 'G' || str[k] == 'H') str[k] = 'E';
            if (str[k] == 'J' || str[k] == 'K' || str[k] == 'L' || str[k] == 'M' || str[k] == 'N') str[k] = 'I';
            if (str[k] == 'P' || str[k] == 'Q' || str[k] == 'R' || str[k] == 'S' || str[k] == 'T') str[k] = 'O';
            if (str[k] == 'V' || str[k] == 'W' || str[k] == 'X' || str[k] == 'Y' || str[k] == 'Z') str[k] = 'U';
        }
        printf("Case #%d:\n", i+1);
        printf("%s\n", str);
        for (int k=0;k<strlen(str); k++) {
            printf("%d", angka[k]);
        }
        printf("\n");
    }
    return 0;
}