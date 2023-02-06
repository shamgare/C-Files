#include <stdio.h>

int main()
{
    int n, k, kasus, spasi;
    long long int sum;
    int arr1[255][255] = {};
    int arr2[255][255] = {};
    
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%d", &n);
        scanf("%d", &k);
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                scanf("%d", &arr1[j][l]);
            }
        }
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                scanf("%d", &arr2[x][y]);
            }
        }
        for (int a = 0; a <= n-k; a++) {
            spasi = 0;
            for (int b = 0; b <= n-k; b++) {
                sum = 0;
                for (int c = a; c < a+k; c++) {
                    for (int d = b; d < b+k; d++) {
                        sum += arr1[c][d] * arr2[c-a][d-b];
                    }
                }
                if (spasi == 0) {
                    printf("%lld", sum);
                    spasi = 1;
                } else {
                    printf(" %lld", sum);
                }
            }
            printf("\n");
        }
    }
}