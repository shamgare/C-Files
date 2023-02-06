#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int find;

    long long arr[5050];
    long long prefix[5050] = {};
    int size; scanf("%d", &size);
    long long num;
    long long x;

    prefix[0] = 0;
    for (int j = 1; j <= size; j++) {
        scanf("%lld", &x);
        prefix[j] = x + prefix[j - 1];
    }
    // for (int j = 1; j <= size; j++) {
    //     printf("%lld\n", prefix[j]);
    // }

    scanf("%d", &find);
    for (int i = 0; i < find; i++) {
        scanf("%lld", &num);
        int max = -43;
        for (int j = 0; j < size; j++) {
            for (int k = size; k >= j + 1; k--) {
                if (prefix[k] - prefix[j] <= num) {
                    if (k - j > max) {
                        max = k - j;
                        break;
                    }
                    if (k - j < max) break;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, max);
    }
}