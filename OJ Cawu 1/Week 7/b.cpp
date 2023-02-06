#include <stdio.h>
#include <string.h>

int main()
{
    FILE* file = fopen("testdata.in", "r");
    int kasus;
    char str[150] = {};
    int num;
    char temp;

    fscanf(file, "%d", &kasus);
    getc(file);

    for (int i = 0; i < kasus; i++) {
        fscanf(file, "%s", str);
        fscanf(file, "%d", &num);
        fscanf(file, "%c", &temp);

        int len = strlen(str);
        char x[150] = {};
        char y[150] = {};
        for (int j = 0; j < num; j++) {
            fscanf(file, "%c %c", &x[j], &y[j]);
            fscanf(file, "%c", &temp);
            // printf("x: %c y: %c\n", x[j], y[j]);
        }

        // counter berapa kali huruf muncul
        int arr[255] = {};
        int arr2[255] = {};
        for (int j = 0; j < len; j++) {
            arr[str[j]]++;
            //  printf("%d ", arr[str[j]]);
        }

        // printf("%s\n", str);
        // ganti character pada string, kalo huruf ngulang, g dituker
        for (int j = 0; j < num; j++) {
            for (int k = j; k < len; k++) {
                if (str[k] == x[j] && arr2[str[k]] <= arr[str[k]]) {
                    str[k] = y[j];
                    arr2[str[k]]++;
                    // printf("%c\n", str[k]);
                    // printf("%d\n", arr2[str[k]]);
                }
                // printf("%s\n", str);
            }
        }

        // printf("%s\n", str);

        // BUBBLE SORT
        for (int j = 0; j < num - 1; j++) {
            for (int k = j + 1; k < num; k++) {
                if (y[k] < y[j]) {
                    char temp = y[j];
                    int temp2 = arr[y[j]];
                    y[j] = y[k];
                    arr[y[j]] = arr[y[k]];
                    y[k] = temp;
                    arr[y[k]] = temp2;
                }
            }
        }

        // print hasil
        for (int j = 0; j < num; j++) {
            if (arr2[y[j]] > 0) {
                printf("%c %d\n", y[j], arr2[y[j]]);
            }
        }

        fclose(file);
    }
}
