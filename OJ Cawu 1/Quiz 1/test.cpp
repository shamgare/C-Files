#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int probC()
{
    int kasus;
    int angka1, angka2;
    
    scanf("%d", &kasus);

    for (int i = 1; i <= kasus; i++) {
        scanf("%d %d", &angka1, &angka2);

        if (angka1 == 0 && angka2 == 0) {
            printf("Case #%d: 0\n", i);
        } else {
            long long int x1[10] = {};
            long long int y1[10] = {};
            long long int result[10] = {};
            int j = 0;
            int k = 0;
            int digitnumber;

            while (angka1 > 0) {
                x1[j] = angka1 % 10;
                angka1 = angka1 / 10;
                j++;
            }
            while (angka2 > 0) {
                y1[k] = angka2 % 10;
                angka2 /= 10;
                k++;
            }

            if (j < k) {
                digitnumber = k;
            } else if (j >= k) {
                digitnumber = j;
            }

            for (int l = 0; l < digitnumber; l++) {
                result[l] = (x1[l] + y1[l]) % 10;
            }

            printf("Case #%d: ", i);

            for (int m = digitnumber - 1; m >= 0; m--) {
                if (result[m] == 0 && m != 0) {
                    continue;
                }
                
                printf("%d", result[m]);
            }
            printf("\n");
        }
        
    }
}

int main()
{
    // int kasus;
    // scanf("%d", &kasus);

    // for (int i = 0; i < kasus; i++) {
    //     char a[10];
    //     char b[10];
    //     int u[10];
    //     int spasi = 0;

    //     scanf("%s %s", a, b);

    //     //1.
    //     if (strlen(a) == strlen(b)) {

    //         for (int angka1 = strlen(a); angka1 >= 1; angka1--) {
    //             u[angka1] = (int) a[angka1-1] - 48 + (int) b[angka1-1] - 48;
    //         }
    //         for (int j = 1; j<=strlen(a); j++) {
    //             if (u[j] == 0) {
    //                 printf("");
    //             } else {
    //                 printf("%d", u[j] % 10);
    //             }
    //         }
    //     }

    //     //2.
    //     if (strlen(a) < strlen(b)) {
    //         char c[10];
    //         strcpy(c, b);
    //         strcpy(b, a);
    //         strcpy(a, c);
    //     }


    // }
    probC();
    return 0;
}