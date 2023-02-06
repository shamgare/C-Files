#include <stdio.h>

// int main()
// {
//     int angka, b, count = 0;
//     for (int i = 0; i < 3; i++) {
//         count = 0;
//         scanf("%d", &angka);
//         b = angka;
//         while (b != 0) {
//             b /= 10;
//             count++;
//         }
//         for (int j = 0; j < count/2; j++) {
//             a /= 10;
//             a %= 10;
//         }
//         printf("%d\n", a);
//         printf("%d\n", count);
//         printf("%d\n", count/2);
//     }
//     return 0;
// }

int main()
{
    int angka = 12345;
    int angka2 = 12345;
    int print;
    int j = 10000;

    int b;
    scanf("%d", &b);

    for (int i = 0; i < b; i++) {
        print = angka %= j;
        j /= 10;
        printf("MOD: %d\n", print);
    }

    for (int i = 0; i < b; i++) {
        angka2 /= 10;
        printf("DIV: %d\n", angka2);
    }
}