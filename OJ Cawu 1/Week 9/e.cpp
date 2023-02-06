#include <stdio.h>

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        long long int size, limit; scanf("%lld %lld", &size, &limit);
        long long int arr[size]; arr[0] = 0;
        long long int num;
        for (int j = 1; j <= size; j++) {
            scanf("%lld", &num);
            arr[j] = num + arr[j-1]; }
        int index = -1;
        for (int j = 0; j < size; j++) {
            for (int k = size; k >= j + 1; k--) {
                if (arr[k] - arr[j] <= limit) {
                    if (k - j > index) { index = k - j; break; }
                }
                if (k - j < index) break;
            }
        }
        printf("Case #%d: %d\n", i+1, index);
    }
}

/*
1 2 3 4 5 = 5 sub, 1 elemen
12 23 34 45 = 4 sub, 2 elemen
123 234 345 = 3 sub, 3 elemen
1234 2345 = 2 sub, 4 elemen
12345 = 1 sub, 5 elemen

*/