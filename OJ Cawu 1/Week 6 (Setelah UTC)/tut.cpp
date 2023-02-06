#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void a(), b(), c();

int main()
{
    //a();
    b();
    //c();
    return 0;
}

void a()
{
    int a, b;
    int num;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    scanf("%d", &num);
    for (int i = 0; i < num-2; i++) {
        a = b;
		b = sum;
		sum = a + b;
    }
    printf("%d\n", sum);
}







void b()
{
    int kasus;
    long long int num, a, b;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%lld %lld %lld", &num, &a, &b);

        long long int sum = -a + b;
        for (int j = 0; j < num; j++) {
            a = b;
            b = sum;
            printf("%lld ", sum);
            sum = -a + b;
        }
        //printf("Case #%d: %lld\n", i+1, sum);
    }
    // 2 3 -1 -2 -3 2
    // x y sum
}






void c()
{
    int kasus;
    long long int awal, akhir;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%lld %lld", &awal, &akhir);

        if (awal == akhir) {
            printf("Case #%d: YES\n", i+1);
        } else {
            while (awal != akhir) {
                if (awal == 1) {
                    awal = awal;
                    break;
                } else if (awal % 2 == 0) {
                    awal = awal/2;
                } else if (awal % 2 == 1) {
                    awal = awal*3 + 1;
                }
            }

            if (awal != akhir) {
                printf("Case #%d: NO\n", i+1);
            } else {
                printf("Case #%d: YES\n", i+1);
            }
        }
    }
}