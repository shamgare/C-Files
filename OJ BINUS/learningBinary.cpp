#include <stdio.h>
#include <stdlib.h>

int main()
{
    getchar();
    long long int num;
    int pos;
    int* arr;
    arr = (int*) malloc(255);

    for (int i = 0; i < 3; i++) {
        scanf("%lld %d", &num, &pos);
        for (int i = 0; i < 8 * sizeof(int); i++) {
            arr[i] = num & 0x01;
            num = num >> 1;
            // printf("%d", arr[i]);
        }
        // printf("\n");
        printf("%d\n", arr[pos]);
        free(arr);
    }
    return 0;
}