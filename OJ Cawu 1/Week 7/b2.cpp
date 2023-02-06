#include <stdio.h>
#include <string.h>

int main()
{
    FILE * file = fopen("testdata.in", "r");
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
        char x;
        char y;

        // counter berapa kali tiap huruf muncul dalam string
        int arr[150] = {};
        for (int j = 0; j < len; j++) {
            arr[str[j] - 65]++;
        }

        // pindahin frekuensi huruf x ke frekuensi huruf y
        // tapi di counter biar tiap huruf cuma bisa 1 kali
        int count[150] = {};
        for (int j = 0; j < num; j++) {
            fscanf(file, "%c %c", &x, &y);
            fscanf(file, "%c", &temp);

            if (count[x] == 0) {
                count[x]++;
                // printf("%d %d\n", arr[y - 65], arr[x - 65]);
                arr[y - 65] += arr[x - 65];
                arr[x - 65] = 0;
            }
        }

        // print sesuai yang counternya > 0
        for (int j = 65; j < 95; j++) {
            if (arr[j - 65] != 0) {
                printf("%c %d\n", j, arr[j - 65]);
            }
        }
    }
}