#include <stdio.h>

void clever(), matrix(), maxEvenSum();

int main()
{
    //clever();
    //matrix();
    maxEvenSum();

    return 0;
}

void clever()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i< kasus; i++) {
        int angka1, angka2;
        int angkaTerakhir, kelipatan = 1, hasil = 0;

        scanf("%d %d", &angka1, &angka2);

        while (angka1 != 0 || angka2 != 0) {
            angkaTerakhir = (angka1 % 10) + (angka2 % 10);
            angkaTerakhir %= 10;
            hasil += (angkaTerakhir*kelipatan);
            kelipatan *= 10;
            angka1 /= 10;
            angka2 /= 10;
        }

        printf("Case #%d: %d\n", i+1, hasil);
    }
}

void matrix()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        float n;
        float k;
        float matriks [100][100] = {};
        scanf("%f", &n);
        scanf("%f", &k);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%f", &matriks[j][k]);
            }
        }

        for (int l = 0; l <= n-k; l++) {
            int spasi = 0;
            for (int m = 0; m <= n-k; m++) {
                float sum = 0;
                for (int o = l; o < l+k; o++) {
                    for (int p = m; p < m+k; p++) {
                        sum += matriks[o][p];
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
}

void maxEvenSum()
{
    int angka;
    scanf("%d", &angka);

    int arr[100000] = {};
    long long int sum = 0;

    for (int i = 0; i < angka; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    if (sum % 2 == 0) {
        printf("%d\n", sum);
    } else {
        int count = 0;
        while (1) {
            if (arr[count] % 2 != 0) {
                printf("%d\n", sum-arr[count]);
                break;
            }
            count++;
        }
    }
}