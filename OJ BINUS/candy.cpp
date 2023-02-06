#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int candy;
        long long int money;
        scanf("%d %lld", &candy, &money);

        long long int arr[candy] = {};
        int min = 1000;
        for (int j = 0; j < candy; j++) {
            scanf("%d", &arr[j]);
            if (arr[j] <= min) {
                min = arr[j];
            }
        }
        
        int count = 0;
        int temp = min;
        while (min <= money) {
            min += temp;
            count++;
        }
        printf("Case #%d: %d\n", i+1, count);
    }
    return 0;
}