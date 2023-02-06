#include <stdio.h>

int main()
{
    int makan; scanf("%d", &makan);
    long long int arr1[makan] = {};
    long long int arr2[makan] = {};
    long long int sumA = 0;
    long long int sumK = 0;
    
    for (int i = 0; i < makan; i++) {
        scanf("%lld", &arr1[i]);
    }
    for (int i = 0; i < makan; i++) {
        scanf("%lld", &arr2[i]);
        sumK += arr2[i];
    }

    
    // if (makan % 2 == 0) {
    //     for (int i = 0; i < makan; i++) {
    //         if (i % 2 == 0) arr1[i] += 2000;
    //         sumA += arr1[i];
    //     }
    // }
    // else {
    //     for (int i = 0; i < makan; i++) {
    //         if (i % 1 == 0) arr1[i] += 2500;
    //         sumA += arr1[i];
    //     }
    // }

    if (sumA > sumK) {
        printf("aan\n");
    }
    else {
        printf("kenken\n");
    }
}