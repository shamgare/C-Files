#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test1()
{
    char* str;
    char* str2;
    char string[] = "Hello";
    int n = 5;
    
    // str = (char*) malloc(n * sizeof(char));
    // str[5] = {};
    str = (char*) calloc(n, sizeof(char));
    str2 = (char*) calloc(n, sizeof(char));

    scanf("%s", str);
    // str = (char*) realloc(str, 25);

    for (int i = 0; i < n; i++) {
        printf("%c\n", str[i]);
    }
    // for (int i = 0; i < n; i++) {
    //     printf("%d\n", &str2[i]);
    // }

    // scanf("%s", str);
    // printf("%s", str);
    free(str);
}

void test2()
{
    char* str;
    str = (char*) malloc(sizeof(char));

    scanf("%c", str);
    int i = 1;
    while (str[i] != '\n') {
        scanf("%c", &str);
        realloc(str, i*2);
        i++;
    }

    printf("%s\n", str);
    free(str);
}

int main()
{
    // test1();
    test2();
}