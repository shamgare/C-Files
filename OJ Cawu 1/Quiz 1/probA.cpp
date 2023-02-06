#include <stdio.h>

int main()
{
    int kasus;
    float n, k;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        float matriks1[101][101] = {};
        scanf("%f", &n);
        scanf("%f", &k);
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                scanf("%f", &matriks1[k][j]);
            }
        }

        for (int l = 0; l <= n - k; l++) {
            int spasi = 0;
            for (int m = 0; m <= n - k; m++) {
                //penjumlahan
                float sum = 0;
                for (int y = l; y < l + k; y++) {
                    for (int z = m; z < m + k; z++) {
                        sum += matriks1[y][z];
                    }
                }
                if (spasi == 0) {
                    printf("%.2f", sum / (k*k));
                    spasi = 1;
                } else {
                    printf(" %.2f", sum / (k*k));
                }
            }
            printf("\n");
        }
    }
    return 0;
}