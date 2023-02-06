#include <stdio.h>

int count;

void bubble(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
}

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int size, time; scanf("%d %d", &size, &time);
        int arr[size] = {};

        for (int j = 0; j < size; j++) { scanf("%d", &arr[j]); }

        count = 0;
        bubble(arr, size);

        printf("Case #%d: %d\n", i+1, count * time);
    }
}


/*

3 4 1 2 9
3 2 1 4 9 1x
2 3 1 4 9 2x
2 1 3 4 9 3x
1 2 3 4 9 4x

2 1 3 4
1 2 3 4 1x

*/