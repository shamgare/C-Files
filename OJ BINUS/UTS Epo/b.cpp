#include <stdio.h>

int main()
{
    int size; scanf("%d", &size);
    long long int arr[size][size] = {};
    long long int arr2[size][size] = {};
    int max = -1;
    int kolom, baris;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lld", &arr[i][j]);
            if (arr[i][j] > max) {
                max = arr[i][j];
                baris = i;
                kolom = j;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == baris) {
                arr2[i][j] = 1;
            }
            if (j == kolom) {
                arr2[i][j] = 1;
            }
        }
    }

    printf("ans:");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr2[i][j] != 1) printf(" %lld", arr[i][j]);
        }
    }
    printf("\n");
}