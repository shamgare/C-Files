#include <stdio.h>

int min(int a, int b)
{
    if (a <= b) return a;
    else return b;
}

int abs(int a)
{
    if (a < 0) return a * -1;
    else return a;
}

int findMinRec(int* arr, int high, int sumCalculated, int sumTotal)
{
    if (high == 0) return abs((sumTotal - sumCalculated) - sumCalculated);
    
    return min(     findMinRec(arr, high - 1, sumCalculated + arr[high - 1], sumTotal),         findMinRec(arr, high - 1, sumCalculated, sumTotal));
}

int findMin(int* arr, int size)
{
    int sumTotal = 0;
    for (int i = 0; i < size; i++) sumTotal += arr[i];
 
    return findMinRec(arr, size, 0, sumTotal);
}

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int size; scanf("%d", &size);
        int arr[size] = {};
        
        for (int j = 0; j < size; j++) scanf("%d", &arr[j]);

        printf("Min difference is %d\n", findMin(arr, size));
    }
}

/*

*/