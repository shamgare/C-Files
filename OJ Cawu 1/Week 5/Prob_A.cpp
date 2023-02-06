#include <stdio.h>

int main()
{
    char kata1[21][21];
    char kata2[21][21];

    scanf("%s", kata1[0]);
    scanf("%s", kata1[1]);
    scanf("%s", kata1[2]);

    scanf("%s", kata2[0]);
    scanf("%s", kata2[1]);
    scanf("%s", kata2[2]);

    int spasi = 1;
    for (int i = 0; i < 3; i++)
    {
        if (spasi == 0)
        {
            printf(" %sszs", kata1[i]);
        }
        else
        {
            printf("%sszs", kata1[i]);
            spasi = 0;
        }
    }
    printf("\n");

    spasi = 1;
    for (int i = 0; i < 3; i++)
    {
        if (spasi == 0)
        {
            printf(" %sszs", kata2[i]);
        }
        else
        {
            printf("%sszs", kata2[i]);
            spasi = 0;
        }
    }
    printf("\n");

    return 0;
}