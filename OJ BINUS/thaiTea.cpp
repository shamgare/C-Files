#include <stdio.h>

int main()
{
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        int beli, refill;
        scanf("%d %d", &beli, &refill);

        int sum = beli;
        int mod;
        while (beli >= 0) {
            mod = beli % refill;
            beli /= refill;
            sum += beli;
            // printf ("%d %d\n", mod, beli);
            if (beli + mod < refill) break; 
            else beli += mod;
        }
        printf("Case #%d: %d\n", i+1, sum);
    }
    return 0;
}

/*
3 2
1 1 1 = 1 cup tambahan
2
1 1 = 1 cup

4 3
1 1 1 1 = 1 cup
2
1 1 = 0 cup

4 2
1 1 1 1 = 2 cup tambahan
2
1 1 = 1 cup tambahan

6 2
11 11 11 = 3 cup
3
11 1 = 1 cup
2
11 = 1 cup

6 3
111 111 = 2 cup
2
1 1 = 0 cup

4
1 1 1 1 = 1 cup
2
1 1 = 0 cup

10 4
1111 1111 11 = 2 cup
1111 = 1 cup

10 3
111 111 111 1 = 3 cup
111 1 = 1 cup
1 = 0 cup


*/