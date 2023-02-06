#include <stdio.h>

int partition(long long int* arr, int low, int high)
{
    int i = low - 1;
    int j = low;
    long long int pivot = arr[high];
    while (j < high) {
        if (arr[j] <= pivot) {
            i++;
            long long int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }
    arr[high] = arr[i+1];
    arr[i+1] = pivot;

    return i+1;
}

void qs(long long int* arr, int low, int high)
{
    if (low < high) {
        int pos = partition(arr, low, high);

        qs(arr, low, pos-1);
        qs(arr, pos+1, high);
    }
}

int main()
{
    int kasus; scanf("%d", &kasus); 
    
    for (int i = 0; i < kasus; i++) { 
        long long int arr[30] = {}, solution[5] = {}, sum = 0;

        for (int j = 0; j < 25; j++) { scanf("%lld", &arr[j]); sum += arr[j]; }

        qs(arr, 0, 24);

        solution[0] = arr[0] / 2; solution[4] = arr[24] / 2;

        if (solution[0] == solution[4]) { solution[1] = solution[4]; solution[2] = solution[4]; solution[3] = solution[4]; } 
        else { solution[1] = arr[1] - solution[0]; solution[3] = arr[23] - solution[4]; solution[2] = arr[4] - solution[0]; }

        printf("Case #%d:", i+1);
        for (int i = 0; i < 5; i++) { printf(" %lld", solution[i]);} printf("\n");
    }
}









/*

4
2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10
3 3 4 4 2 2 3 3 3 2 3 2 3 3 2 2 2 3 2 2 3 3 4 4 3
4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
5 7 6 7 10 8 2 3 4 11 11 3 4 5 6 8 9 7 8 9 4 6 7 8 12

            // sum array = 10a + 10b + 10c + 10d + 10e
            // sum dari array awal dikurang (10a + 10b + 10d + 10e), terus dibagi 10 untuk mendapat c
            // long long int temp = (solution[0] * 10) + (solution[1] * 10) + (solution[3] * 10) + (solution[4] * 10);
            // sum = sum - temp; 
            // sum = sum / 10;
            // solution[2] = sum;
*/