#include <stdio.h>

void tree(int* arr, int max, int num, int sum)
{
    if (num == max) {
        printf("%d\n", sum);
        return;
    } else if (num * 2 == max) {
        printf("%d\n", sum + arr[num * 2]);
        return;
    } else if (num * 2 > max) {
        printf("%d\n", sum);
        return;
    }

    //kiri
    tree(arr, max, num*2, sum + arr[num*2]);
    //kanan
    tree(arr, max, num*2 + 1, sum + arr[num*2 + 1]);
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int len = 7;

    printf("Case 1:\n");
    tree(arr, len, 1, arr[1]);
    
    return 0;
}

/*
                 1
            2         3
        4       5 6       7

*/