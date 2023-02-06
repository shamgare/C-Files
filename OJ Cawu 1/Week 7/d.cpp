#include <stdio.h>
#include <string.h>

int main()
{
    FILE * (file) = fopen("testdata.in", "r");
    int kasus;
    char get;
    int perubahan;
    char str[1005] = {};

    fscanf(file, "%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        fscanf(file, "%d", &perubahan);
        fscanf(file, "%c", &get);
        fscanf(file, "%[^\n]", str);

        for (int j = 0; j < strlen(str); j++) {
            if (str[j] == '0') str[j] = 'O';
            else if (str[j] == '1') str[j] = 'I';
            else if (str[j] == '3') str[j] = 'E';
            else if (str[j] == '4') str[j] = 'A';
            else if (str[j] == '5') str[j] = 'S';
            else if (str[j] == '6') str[j] = 'G';
            else if (str[j] == '7') str[j] = 'T';
            else if (str[j] == '8') str[j] = 'B';
        }

        for  (int j = 0 ; j < strlen(str); j++) {
            if (str[j] != ' ') str[j] = str[j] - perubahan;
            if (str[j] < 65 && str[j] != ' ') str[j] = str[j] + 26;
        }
        printf("Case #%d: %s\n", i+1, str);
    }
    

    return 0;
}