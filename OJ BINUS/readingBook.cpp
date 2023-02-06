#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int page, target;
        scanf("%d %d", &page, &target);
        
        int start;
        if (1 + target < page - target) {
            start = 1;
        } else {
            start = page;
        }
        
        int count = 0;
        printf("%d\n", count);
    }
}

/*
10
1 23 45 67 89 910
55 0    106
54 0
51 0
52 1
53 2

100
1 23 ... 9899 100

*/