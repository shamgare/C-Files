#include <stdio.h>

void algo1()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int num; scanf("%d", &num);

        int arr[num] = {};
        int arr2[num] = {};
        int index = 0;
        
        for (int a = 0; a <= num; a++) {
            for (int b = 0; b <= num; b++) {
                if (a + b == num) {
                    arr[index] = a; arr2[index] = b;
                    index++;
                    printf("%d dan %d\n", a, b);
                }
            }
            if (a > num / 2) break;
        }

        if (num % 2 == 1) {
            for (int x = 0; x < index / 2; x++) {
                printf("%d dan %d\n", arr2[x], arr[x]);
            }
        } else {
            for (int x = 0; x < index / 2 - 1; x++) {
                printf("%d dan %d\n", arr2[x], arr[x]);
            }
        }
    }
}

void algo2()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int size, num; scanf("%d %d", &size, &num);
        int arr[size] = {};

        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }

        int check[1005] = {};
        int check2[1005] = {};
        int index = 0;

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (arr[j] + arr[k] == num) {
                    if (check2[arr[j]] == 0 && check[arr[k]] == 0) {
                        printf("%d %d\n", arr[j], arr[k]);
                    }
                    check[arr[j]]++; check2[arr[k]]++;
                    check2[arr[j]]++; check[arr[k]]++;
                    index++;
                }
            }
        }
    }
}

int binary(int* arr, int find, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == find) {
            return mid;
        }
        else if (arr[mid] < find) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int part(int* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    int pivot = arr[high];

    while (j < high) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;

    return i + 1;
}

void qs(int* arr, int low, int high)
{
    if (low < high) {
        int pos = part(arr, low, high);

        qs(arr, low, pos - 1);
        qs(arr, pos + 1, high);
    }
}

void algo3()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int x, size; scanf("%d %d", &size, &x);
        int arr[size] = {};
        
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[j]);
        }

        qs(arr, 0, size - 1);
        
        for (int j = 0; j < size; j++) {
            if (binary(arr, x - arr[j], size) != -1) {
                int index = binary(arr, x - arr[j], size);
                
                printf("%d %d\n", arr[j], arr[index]);
                arr[j] = -99;
            }
        }
    }
}

int main()
{
    // algo1();
    // algo2();
    algo3();
}

/*
01
02
03
04




*/