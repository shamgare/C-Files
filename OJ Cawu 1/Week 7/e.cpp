#include <stdio.h>
#include <stdlib.h>

void tree(int* arr, int limit, int index, int sum)
{
    if (index == limit) {
        printf("%d\n", sum);
        return;
    } else if (index*2 == limit) {
        printf("%d\n", sum + arr[index * 2]);
        return;
    } else if (index*2 > limit) {
        printf("%d\n", sum);
        return;
    }

    tree(arr, limit, index*2, sum + arr[index*2]);
    tree(arr, limit, index*2 + 1, sum + arr[index*2 + 1]);
}

int main()
{
    int kasus;
    int num;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%d", &num);

        int arr[150] = {};
        for (int j = 1; j <= num; j++) {
            scanf("%d", &arr[j]);
        }

        printf("Case #%d:\n", i+1);
        tree(arr, num, 1, arr[1]);
    }
    
    return 0;
}