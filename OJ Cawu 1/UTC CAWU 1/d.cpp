#include <stdio.h>
//soal duo

int main()
{
    long long int kasus = 0, count;
    scanf("%lld", &kasus);
    
    for (int i = 0; i < kasus; i++) {
        long long int banyak = 0, num = 0, temp = 0;
        count = 0;
        scanf("%lld", &banyak);
        for (int j = 0; j < banyak; j++) {
            scanf("%lld", &num);
            if (num > temp) {
                temp = num;
            } else if (temp == num) {
                count++;
                temp = 0;
            }
        }
        printf("Case #%d: %lld\n", i+1, count);
    }
}

// tiap mulai for, count di reset dan temp di reset biar selalu mulai dari 0,
// temp nyimpen angka sebelumnya, 
// jika angka sebelumnya sama dgn angka setelahnya, count+1 DAN reset angka sebelumnya,
// tapi kalo ngga sama dan angka setelahnya malah lebih gede dri angka sebelumnya, set angka sebelumnya jadi angka yg baru aja di scan.

// int main ()
// {
//     int kasus;
//     scanf("%s", &kasus);

//     long long int banyak;
//     long long int arr[255] = {};
//     long long int count[255] = {};
//     int x;

//     for (int i = 0; i < kasus; i++) {
//         x = 0;
//         memset(count,0,sizeof(count));
//         scanf("%lld", &banyak);

//         for (int j = 0; j < banyak; j++) {
//             scanf("%d", &arr[j]);
//             count[arr[j]]++;
//             if (count[arr[j]] >= 2 && count[arr[j]] < 4) {
//                 x++;
//                 count[arr[j]] = 0;
//             }
//         }
//         printf("Hasil: %d\n", x);
//     }
// }

// int main()
// {
//     int kasus, byk, num, count, temp;
//     scanf("%d", &kasus);
//     for (int i = 0; i < kasus; i++) {
//         count = 0;
//         temp = 0;
//         scanf("%d", &byk);
//         for (int j = 0; j < byk; j++) {
//             scanf("%d", &num);
//             if (temp == num) {
//                 count++;
//                 temp = 0;
//             } else if (num > temp) temp = num;
//         }
//         printf("%d\n", count);
//     }
// }
