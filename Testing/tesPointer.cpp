#include <stdio.h>

int main()
{
    int age = 8;
    int *pAge = &age;
    // int **ppAge = &pAge;

    printf("Age is %d\n", age);
    printf("Age value is stored at %p\n", &age);
    *pAge = 8*2;
    
    printf("Age is %d\n", *pAge);
    printf("Age is %d\n", age);
}