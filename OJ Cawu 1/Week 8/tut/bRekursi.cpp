#include <stdio.h>

long long int sum(int* arr, int limit)
{
    if (limit == 0) return arr[0];
    return (arr[limit] + sum(arr, limit-1));
}

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        int num; scanf("%d", &num); int arr[num];
        for (int j = 0; j < num; j++) scanf("%d", &arr[j]);
        printf("%lld\n", sum(arr, num-1));
    }
}

