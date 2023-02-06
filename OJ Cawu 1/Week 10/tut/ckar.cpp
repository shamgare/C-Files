#include <stdio.h>

int main ()
{
    FILE* file = fopen("testdata.in", "r");
    int min;
    fscanf(file, "%d\n", &min);
    
    char words[1050];
    int page = 1;
    int counterr = 0;
    int flag = 1;

    while (!feof(file)) {
        fscanf(file, "%s", words);
        if (words[0] == '#') {
            if (counterr < min) {
                printf("page %d: %d word(s)\n", page, counterr);
                flag = 0;
            }
            counterr = 0;
            page++;
        } else {
            counterr++;
        }
    }

    if (flag == 1) {
        printf("The essay is correct\n");
    }
        
    fclose(file);
    return 0;
}