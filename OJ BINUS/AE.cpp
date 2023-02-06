#include <stdio.h>

int main()
{
    int angka;
    scanf("%d", &angka);

    int bonus = 0;
    int sum = angka*100;
    for (int i = 0; i < angka - 1; i++) {
        bonus += 50;
        sum += bonus;
    }
    printf("%d\n", sum);

    return 0;
}