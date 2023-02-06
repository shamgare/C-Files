#include <stdio.h>

int main()
{
    char str[150] = {}, str2[150] = {};
    double height, height2;
    int umur, umur2;

    scanf("%s %lf %d %s %lf %d", str, &height, &umur, str2, &height2, &umur2);
    printf("Name 1: %s\n", str);
    printf("Height 1: %.2lf\n", height);
    printf("Age 1: %d\n", umur);
    printf("Name 2: %s\n", str2);
    printf("Height 2: %.2lf\n", height2);
    printf("Age 2: %d\n", umur2);
    return 0;
}