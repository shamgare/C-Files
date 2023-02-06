#include <stdio.h>

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int x = 0; x < kasus; x++) {
        int tangga;
        int nafas;
        scanf("%d %d", &tangga, &nafas); getchar();
        
        char anak;
        int reset = nafas;
        int bol = 0;
        for (int i = 0; i < tangga; i++) {
            scanf("%c", &anak);
            if (nafas == 0) break;
            if (anak == '1') nafas = reset;
            if (i == tangga-1) bol = 1;
            nafas--;
        }
        getchar();
        if (bol == 0) printf("Dead\n");
        else printf("Alive\n");
    }

    return 0;
}