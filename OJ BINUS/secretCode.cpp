#include <stdio.h>

int main()
{
    int k; scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int num;
        char code[1005] = {};
        scanf("%d %s", &num, code);
        for (int j = 0; j < num; j++) {
            int idx, idx2;
            scanf("%d %d", &idx, &idx2);
            char temp = code[idx - 1];
            code[idx - 1] = code[idx2 - 1];
            code[idx2 - 1] = temp;
        }
        printf("Case #%d: %s\n", i+1, code);
    }
    return 0;
}