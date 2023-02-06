#include <stdio.h>

int main()
{
    FILE * fpointer = fopen("testdata.in", "r");

    int a, b;
    fscanf(fpointer, "%d %d", &a, &b);
    
    int c = a + b;
    fclose(fpointer);
    printf("%d\n", c);
}