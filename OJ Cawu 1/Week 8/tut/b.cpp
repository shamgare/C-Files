#include <stdio.h>

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        long long int num; scanf("%lld", &num);
        long long int sum = 0;
        long long int angka;
        for (int j = 0; j < num; j++) {
            scanf("%lld", &angka);
            sum += angka;
        }
        printf("Case #%d: %lld\n", i+1, sum);
    }
}