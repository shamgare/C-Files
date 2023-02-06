#include <stdio.h>

int main ()
{
    int matriks1[10][10];
    int matriks2[10][10];
    int hasil[10][10];
    int a, b, c, d;

    printf("Ukuran matriks 1: ");
    scanf("%d %d", &a, &b);
    printf("Ukuran matriks 2: ");
    scanf("%d %d", &c, &d);

    if (b != c) {
        printf("Matrix can not be multiplied.\n");
    } else {
        printf("Input angka matriks 1:\n");
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                scanf("%d", &matriks1[i][j]);
            }
        }
        printf("Input angka matriks 2:\n");
        for (int k = 0; k < c; k++) {
            for (int l = 0; l < d; l++) {
                scanf("%d", &matriks2[k][l]);
            }
        }

        printf("Hasil perkalian matriks:\n");
        for (int x = 0; x < a; x++) {
            int spasi = 0;
            for (int y = 0; y < d; y++) {
                hasil[x][y] = 0;
                for (int z = 0; z < b; z++) {
                    hasil[x][y] += matriks1[x][z] * matriks2[z][y];
                }
                if (spasi == 0) {
                    printf("%d", hasil[x][y]);
                    spasi = 1;
                } else {
                    printf(" %d", hasil[x][y]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}