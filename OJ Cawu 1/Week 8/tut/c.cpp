#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int num;
    scanf("%lld", &num);

    long long int arr[num];
    int* count = (int*) malloc(sizeof(int) * (2 * pow(10, 9)));
    long long int sum = 0;

    for (int i = 0; i < num; i++) {
        scanf("%lld", &arr[i]);
        count[arr[i]]++;
        if (count[arr[i]] == 1) sum++;
    }
    printf("%lld\n", sum);
}