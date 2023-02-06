#include <stdio.h>

int main()
{
    long long int num;
    scanf("%lld", &num);

    long long int nomor[num];
    long long int sum = 0;
    long long int count[num] = {};

    for (int i = 0; i < num; i++) {
        scanf("%lld", &nomor[i]);
        count[nomor[i]]++;

    }
    for (int i = 0; i < num; i++) {
        printf("%d ", count[nomor[i]]);
        if (count[nomor[i]] > 0) sum++;
    }
    printf("%lld\n", sum);
}