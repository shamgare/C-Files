#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int arr[255] = {};
bool check[255];

int fktrl(int a)
{
    if (a == 1 || a == 0) return 1;
    return a * fktrl(a-1);
}

int fib(int a)
{
    if (a <= 1) return a;
    return fib(a-1) + fib(a-2);
}

void print(int index, int num)
{
    if (index >= num) {
        Sleep(200);
        for (int i = 0; i < num; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= num; i++) {
            arr[index] = i;
            print(index + 1, num);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    // printf("%d\n", fktrl(num));
    // printf("%d\n", fib(num));

    // for (int i = 1; i <= 3; i++) {
    //     for (int j = 1; j <= 3; j++) {
    //         for (int k = 1; k <= 3; k++) {
    //             if (i != j && j != k && k != i) printf("%d%d%d\n", i, j, k);
    //         }
    //     }
    // }

    print(0, num);
}