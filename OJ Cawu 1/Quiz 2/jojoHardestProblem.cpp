#include <stdio.h>

long long int arr[400050];

void algo1()
{
    long long int size; scanf("%lld", &size);
    
    for (int j = 0; j < size; j++) scanf("%lld", &arr[j]);

    long long int limit; scanf("%lld", &limit);

    long long int sums = 0, max = -1;
    
    for (int j = 0; j < size; j++) {
        sums = 0;
        long long int k = size - j;
        for (int x = j; x < size; x++) {
            printf("%lld [%lld] %lld\n", sums, arr[x], k);
            if (sums + arr[x] * k <= limit) sums += arr[x] * k;
            else break;
            k--;
        }
        if (sums > max) max = sums;
    }
    printf("%lld\n", max);
}





int part(int low, int high)
{
    int i = low - 1;
    int j = low;
    long long int pivot = arr[high];

    while (j < high) {
        if (arr[j] <= pivot) {
            i++;
            long long int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;

    return i + 1;
}

void qs(int low, int high)
{
    if (low < high) {
        int pos = part(low, high);

        qs(low, pos - 1);
        qs(pos + 1, high);
    }
}

long long int sum;
long long counter = 0;

long long int func(int x, int k, long long int limit)
{
    if (k == 0 || sum > limit) return sum;

    printf("%lld %lld %d\n", sum, arr[x], k);
    
    if (sum + arr[x] * k <= limit) sum += arr[x] * k;
    
    func(x + 1, k - 1, limit);
}

void algo2()
{
    long long int size; scanf("%lld", &size);
    long long int limit;
    
    for (int i = 0; i < size; i++) scanf("%lld", &arr[i]);
    
    scanf("%lld", &limit);

    long long int max = -1;
    for (int i = 0; i < size; i++) {
        sum = 0;
        if (func(i, size - i, limit) > max) max = func(i, size - i, limit);
    }
    
    printf("%lld\n", max);
    // printf("%lld\n", counter);
}
// bisa sampai 25000 calls


int main(int argc, char const *argv[])
{
    // algo1();
    algo2();
}












/*
arr size = 5

[0] * 5
[1] * 4
[2] * 3
[3] * 2
[4] * 1

[1] * 4
[2] * 3
...


1 * 5
2 * 4
3 * 3
4 * 2
5 * 1

2 * 4
3 * 3
4 * 2
5 * 1

3 * 3
4 * 2
5 * 1

*/