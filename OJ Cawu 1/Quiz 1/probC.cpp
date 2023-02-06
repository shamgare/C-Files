#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// int main()
// {
//     int kasus;
//     scanf("%d", &kasus);

//     char angka1[10], angka2[10];
//     int a1, a2;
//     int a[10];
//     int selisih;
//     int sama[10];

//     for (int i = 0; i< kasus; i++) {
//         char angka1[10] = {};
//         char angka2[10] = {};
//         int a[10] = {};

//         scanf("%s %s", &angka1, &angka2);
//         a1 = atoi(angka1);
//         a2 = atoi(angka2);
    
//         if (strlen(angka1) == strlen(angka2)) {
//             printf("Case #%d: ", i+1);
//             for (int k = 0; k<strlen(angka1); k++) {
//                 sama[k] = (angka1[k] - 48 + angka2[k] - 48)  % 10;
//             }
//             for (int k = strlen(angka1) - 1; k>=0; k--) {
//                 if (sama[k] != 0) {
//                     printf("%d", sama[k]);
//                 }
//             }
//             printf("\n");
//         } else {
//             if (strlen(angka1) < strlen(angka2)) {
//                 char c[10];
//                 strcpy(c, angka2);
//                 strcpy(angka2, angka1);
//                 strcpy(angka1, c);
//                 a1 = atoi(angka1);
//                 a2 = atoi(angka2);
//                 selisih = strlen(angka1) - strlen(angka2);
//             }

//             if (strlen(angka1) > strlen(angka2)) {
//                 for (int j = strlen(angka1) - 1; j>=0; j--) {
//                     a[j] = (angka1[j] - 48 + angka2[j-selisih] - 48) % 10;
//                 }

//                 printf("Case #%d: ", i+1);

//                 for (int k = 0; k<strlen(angka1); k++) {
//                     printf("%d", a[k]);
//                 }
//                 printf("\n");
//             }
//         }
//     }
//     return 0;
// }

int joel()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int A, B;
        int angkaBit, result = 0, j = 1;
        scanf("%d %d", &A, &B);
        printf("Case #%d: ", i+1);  
        while (A != 0 || B != 0)
        {
            angkaBit = (A % 10) + (B % 10);

            angkaBit %= 10;

            result = (angkaBit * j) + result;

            A/=10;
            B/=10;

            j *= 10;
        }
        printf("%d\n", result);
    }
    
}

int main()
{
    int kasus;
    int angka1, angka2;
    scanf("%d", &kasus);

    for (int i = 0; i<kasus; i++) {
        scanf("%d %d", &angka1, &angka2);
        if (angka1 == 0 && angka2 == 0) {
            printf("Case #%d: 0\n", i+1);
        } else {
            long long int a1[1000] = {};
            long long int a2[1000] = {};
            int j = 0, k = 0;
            int length;
            long long int hasil[1000] = {}; 
            while (angka1 > 0) {
                a1[j] = angka1 % 10;
                angka1 /= 10;
                j++;
            }
            while (angka2 > 0) {
                a2[k] = angka2 % 10;
                angka2 /= 10;
                k++;
            }
            if (j < k) {
                length = k;
            } else if (j >= k) {
                length = j;
            }

            for (int l = 0; l<length; l++) {
                hasil[l] = (a1[l] + a2[l]) % 10;
            }

            printf("Case #%d: ", i + 1);

            for (int m = length - 1; m >=0 ; m--) {
                if (m != 0 && hasil[m] == 0) {
                    continue;
                }
                printf("%d", hasil[m]);
            }
            printf("\n");
        }
        //joel();
    }
    return 0;
}