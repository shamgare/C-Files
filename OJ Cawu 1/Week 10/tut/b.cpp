#include <stdio.h>
#include <string.h>

char map[105][105] = {};
int baris;
int kolom;
int count;

void pacmon(int x, int y, char old, char neww)
{
    if (x < 0 || x >= baris || y < 0 || y >= kolom || map[x][y] != old) return;

    map[x][y] = neww; count++;
    pacmon(x+1, y, old, neww);
    pacmon(x, y+1, old, neww);
    pacmon(x-1, y, old, neww);
    pacmon(x, y-1, old, neww);
}

int main()
{
    int kasus; scanf("%d", &kasus); getchar();
    for (int i = 0; i < kasus; i++) { 
        count = 0;
        scanf("%d %d", &baris, &kolom); getchar();
        memset(map, 0, 10000 * sizeof(char));
        int x, y;
        for (int j = 0; j < baris; j++) {
            for (int k = 0; k < kolom; k++) {
                scanf("%c", &map[j][k]);
                if (map[j][k] == 'S'){
                    x = j;
                    y = k;
                    map[j][k] = '.';
                }
            }
            getchar();
        }
        char old = map[x][y];
        char neww = ',';
        pacmon(x, y, old, neww);
        
        printf("Case #%d: %d\n", i+1, count - 1);
    }
}