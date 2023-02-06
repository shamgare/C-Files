#include <stdio.h>

int main()
{
    int tangga;
    scanf("%d", &tangga);

    int num[tangga + 1] = {};
    for (int i = 0; i < tangga; i++) {
        scanf("%d", &num[i]);
    }

    int count = 0;
    for (int j = 0; j < tangga; j++) {
        if (j != 0 && num[j] == 1) {
            printf("%d ", count);
            count = 0;
        }
        count++;
        if (j == tangga - 1) {
            printf("%d\n", count);
        }
    }

    return 0;
}