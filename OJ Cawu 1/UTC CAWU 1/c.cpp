#include <stdio.h>

// soal deposito

int main()
{
    double money, interest;
    long long int kasus, n, in;
    scanf("%lld", &kasus);

    for (int i = 0; i < kasus; i++) {
        money = 0;
        scanf("%lf %lld %lld", &money, &in, &n);
        printf("Case #%d:\n", i+1);

        for (int j = 1; j <= n; j++) {
            interest = 0;
            interest = (money * 0.01 * in / 12 * 0.8);
            money = money + (int) interest;
            printf("%d %.0lf\n", j, money);
        }
    }
    return 0;
}