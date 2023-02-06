#include <stdio.h>

void printArr(int x, int *arr);

int func(int a)
{
    int arr[255] = {};
    int max = -1111110;
    int min = 9999999;
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int x = a;
    printArr(x, arr);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

void printArr(int x, int *arr)
{
    for (int i = 0; i < x; i++) printf("arr[%d]: %d\n", i, arr[i]);
}

int main()
{
    int a;
    scanf("%d", &a);
    func(a);
}