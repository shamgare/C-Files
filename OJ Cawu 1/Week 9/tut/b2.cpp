#include<stdio.h>

long long arr[5000];

void quickSort(int left, int right) {
    int i = left, j = right;
    long long tmp;
    long long pivot = arr[(left + right) / 2];
 
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
 
    if (left < j) quickSort(left, j);
    if (i < right) quickSort(i, right);
}

int main()
{
    int kasus; scanf("%d", &kasus);

    int size;
    for (int i = 0; i < kasus; i++) {
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            scanf("%lld", &arr[j]);
        }

        quickSort(0, size-1);

        long long max = 0;
        for (int j = 1; j < size / 2; j++) {
            if (j == 1) {
                max = arr[j] - arr[j - 1];
            } else {
                if (arr[j] - arr[j - 1] > max) max = arr[j] - arr[j - 1];
            }
        }
        
        for (int j = size/2 + 1; j < size; j++) {
            if (arr[j] - arr[j - 1] > max) max = arr[j] - arr[j - 1];   
        }

        printf("Case #%d: %lld\n", i + 1, max);
    }
}