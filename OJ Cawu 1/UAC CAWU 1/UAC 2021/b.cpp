#include <stdio.h>

int partY(long long int* y, int low, int high)
{
    int i = low - 1;
    int j = low;
    long long int pivot = y[high];

    while (j < high) {
        if (y[j] <= pivot) {
            i++;
            long long int temp = y[j];
            y[j] = y[i];
            y[i] = temp;
        }
        j++;
    }
    y[high] = y[i+1];
    y[i+1] = pivot;

    return i+1;
}

void qsY(long long int* y, int low, int high)
{
    if (low  < high) {
        int pos = partY(y, low, high);

        qsY(y, low, pos-1);
        qsY(y, pos+1, high);
    }
}

int partX(long long int* x, int low, int high)
{
    int i = low - 1;
    int j = low;
    long long int pivot = x[high];

    while (j < high) {
        if (x[j] <= pivot) {
            i++;
            long long int temp = x[j];
            x[j] = x[i];
            x[i] = temp;
        }
        j++;
    }
    x[high] = x[i+1];
    x[i+1] = pivot;

    return i+1;
}

void qsX(long long int* x, int low, int high)
{
    if (low  < high) {
        int pos = partX(x, low, high);

        qsX(x, low, pos-1);
        qsX(x, pos+1, high);
    }
}

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        int shape; scanf("%d", &shape);

        int kordinat = (4 * shape) - 1;
        long long int x[kordinat] = {};
        long long int y[kordinat] = {};

        for (int j = 0; j < kordinat; j++) {
            scanf("%lld %lld", &x[j], &y[j]);
        }

        qsX(x, 0, kordinat-1);
        qsY(y, 0, kordinat-1);

        for (int j = 0; j < kordinat; j++) {
            printf("%lld %lld\n", x[j], y[j]);
        }
        long long int missingX = 0, missingY = 0;
        long long int temp = x[0], temp2 = y[0];
        long long int count = 0, count2 = 0;

        for (int j = 1; j < kordinat; j++) {
            if (temp == x[j]) {
                count++;
            } else {
                if (count % 2 == 0) {
                    missingX = x[j-1];
                    count = 0;
                    break;
                } else {
                    missingX = x[j];
                    count = 0;
                }
                temp = x[j];
            }
        }

        for (int j = 1; j < kordinat; j++) {
            if (temp2 == y[j]) {
                count2++;
            } else {
                if (count2 % 2 == 0) {
                    missingY = y[j-1];
                    count2 = 0;
                    break;
                } else {
                    missingY = y[j];
                    count2 = 0;
                }
                temp2 = y[j];
            }
        }
        printf("Case #%d: %lld %lld\n", i+1, missingX, missingY);
    }
}