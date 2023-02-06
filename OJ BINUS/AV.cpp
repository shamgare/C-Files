#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    int count = 0;
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {
            for (int k = 0; k <= num; k++) {
                if (i + j + k == num) {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
    
    return 0;
}