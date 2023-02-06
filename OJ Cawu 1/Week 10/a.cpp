#include <stdio.h>
#include <math.h>

void algoYangSalah()
{
    int size; scanf("%d", &size); getchar();
    int arr[13]; arr[0] = -1; arr[1] = -1;

    for (int j = 2; j < 13; j++) { arr[j] = 2 + arr[j-1]; }

    int x = -1;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            for (int j = 0; j < size * 2 + arr[size - 1]; j++) {
                printf("*");
            }
        }
        for (int j = 0; j < x; j++) {
            printf("  ");
        }
        for (int j = 0; j < arr[size]; j++) {
            if (i != 0) printf(" *");
        }

        x++;
        if (i > 0) arr[size] -= 2;

        printf("\n");
    }
}

void algoYangBenar()
{
    int size; scanf("%d", &size);

    int arr[size];
    for (int i = 1; i < size; i++) arr[i] = pow(2, i) - 1;

    for (int i = 0; i < size; i++) {
        int max = 0;
        for (int j = 0; j < pow(2, size) - 1; j++) {
            int power = pow(2, i);
            if (i != 0) {
                if (j % power == 0 && j != 0) { printf("*"); max++; }
                else if (j != 0 && max < arr[size-i]) printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main()
{
    algoYangBenar();
    // algoYangSalah();
}


// 6  5  4 3 2
// 31 15 7 3 1
// 







/*
1 1 | size x2 - 1     / 1 + 0
2 3 | size x2 - 1     / 2 + 1

3 7 | size x2 + 1     / 3 + 4
4 11 | size x2 + 3    / 4 + 7
5 15 | size x2 + 5    / 5 + 10
6 19 | size x2 + 7    / 6 + 13
7 23 | size x2 + 9    / 7 + 16


else if (j % 2 == 1 && j != size * 2 + arr[size - 1] - 2) printf("*");
else if (j == size * 2 + arr[size - 1] - 2) break;
else printf(" ");

arr 0 1 2 3 4 5 6 7
isi 1 3 5 7 9
*******
 * * *
   *
***********
 * * * * *
   * * *
     *
***************
 * * * * * * *
   * * * * *
     * * *
       *
*/