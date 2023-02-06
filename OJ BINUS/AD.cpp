#include <stdio.h>

int main()
{
    int num;
    int arr[1005] = {};
    scanf("%d", &num);
    
    int angka = 0;
    for (int i = 0; i < num; i++) {
        scanf("%d", &angka);
        arr[angka]++;
    }

    int max = -1;
    int print = 0;
    for (int i = 0; i < 1005; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%d\n", max);
    return 0;
}