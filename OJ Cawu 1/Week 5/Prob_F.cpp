#include <stdio.h>

int main()
{
    int kasus, a;
    scanf("%d", &kasus);
    for (int i = 0; i<kasus;i++) {
        scanf("%d", &a);
        int bahan[a];
        for (int k = 0; k<a; k++) {
            scanf("%d", &bahan[k]);
        }
        int harga[a];
        for (int j = 0; j<a; j++) {
            scanf("%d", &harga[j]);
        }

        printf("Case #%d: ", i+1);
        int spasi = 0;
        for (int k = 0;k<a;k++) {
            if (spasi == 1) {
                printf(" %d", bahan[k] - harga[k]);
            } else {
                printf("%d", bahan[k] - harga[k]);
                spasi = 1;
            }
        }
        printf("\n");
    }

    return 0;
}