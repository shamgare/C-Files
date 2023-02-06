#include <stdio.h>

int main()
{
    int kasus; scanf("%d", &kasus); getchar();
    int finish = 0;
    for (int i = 0; i < kasus; i++) {
        scanf("%d", &finish);

        int count = 0;
        for (int j = 0; j < finish; j += count) {
            count++;
        }
        printf("Case #%d: %d\n", i+1, count);
    }
    return 0;
}

// 0 1 3 6 10 15
// +1 +2 +3 +4 +5