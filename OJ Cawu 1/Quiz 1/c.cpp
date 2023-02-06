#include <stdio.h>

int main()
{
    int angka;
    scanf("%d", &angka);

    int arr[100010] = {};
    long long int sum = 0;

    for (int i = 0; i < angka; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    if (sum % 2 == 0) {
        printf("%lld\n", sum);
    } else {
        int count = 0;
        while (1) {
            if (arr[count] % 2 != 0) {
                printf("%lld\n", sum-arr[count]);
                break;
            }
            count++;
        }
    }
    return 0;
}