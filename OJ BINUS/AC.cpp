#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", (2<<a-1) - 1);
}