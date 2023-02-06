#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int tinggi;
        scanf("%d", &tinggi);

        for (int j = 0; j < tinggi; j++) {
            for (int k = 0; k < tinggi+j; k++) {
                if (tinggi > j + k + 1) printf(" ");
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}