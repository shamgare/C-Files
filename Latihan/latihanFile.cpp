#include <stdio.h>

int file()
{
    char line[255];

    // FILE * fpointer = fopen("testing.txt", "w");
    // fprintf(fpointer, "PPTI 16\nPPTI 15\nPPTI 14\n");
    // fclose(fpointer);

    FILE * fpointer = fopen("shortcuts.txt", "r");
    fgets(line, 255, fpointer);
    printf("%s", line);
    fgets(line, 255, fpointer);
    printf("%s", line);
    fgets(line, 255, fpointer);
    printf("%s", line);
    
    fclose(fpointer);
}

int main()
{
    file();
}