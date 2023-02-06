#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    // char* values = (char*)malloc(2 * sizeof(char));
    // for (int i = 0; i < 20; i++)
    // {
    //     scanf("%c", &values[i]);
    //     realloc(values, (i * 2) * sizeof(char));
    // }
    // printf("%s\n", values);

    int index = 0;
    while (index++ < 100000)
    {
        int size = 10000000; 
        long long int i;
        int* values = (int*)malloc(size * sizeof(int));

        for (i = 0; i < size; i++) values[i] = i;
        for (i = 0; i < size; i++) printf("%d", values[i]);

        printf("Success\n");
        Sleep(10000);
        free(values);
    }
    
    return 0;
}