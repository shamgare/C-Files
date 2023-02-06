#include <stdio.h>
#include <string.h>

int main()
{
    FILE* file = fopen("testdata.in", "r");

    char words[11][2000] = {};

    int min, page = 1;
    fscanf(file, "%d\n", &min);
    int count[page] = {};
    int flag = 0;

    while (!feof(file)) {
        fscanf(file, "%[^#]#", words[page]);
        for (int j = 0; j < strlen(words[page]); j++) {
            if (words[page][j] >= 97 && words[page][j] <= 122) {
                count[page]++;
            }
        }
        if (strlen(words[page]) - count[page] < min) {
            printf("page %d: %d word(s)\n", page, strlen(words[page]) - count[page]);
            flag++;
        }
        page++;
    }

    if (flag == 0) printf("The essay is correct\n");

    fclose(file);
}