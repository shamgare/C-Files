#include <stdio.h>

int main()
{
    int kasus;
    int angka[10] = {};
    int jumlah;
    
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int p = 0, q = 0;
        angka[1050] = {};

        scanf("%d", &jumlah);
        
        for (int k = 0; k < jumlah; k++) {
            scanf("%d", &angka[k]);
        }

        scanf("%d %d", &p, &q);

        if (angka[p-1] < angka[q-1]) {
            printf("Case #%d : Lili\n", i+1);
        } else if (angka[p-1] > angka[q-1]) {
            printf("Case #%d : Bibi\n", i+1);
        } else {
            printf("Case #%d : Draw\n", i+1);
        }
    }
    return 0;
}