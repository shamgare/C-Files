#include <stdio.h>

char map[101][101] = {};
int count = 0;

void flood(int x, int y, int baris, int kolom)
{
    if (x < 0 || y < 0 || x >= baris || y >= kolom || map[x][y] != '.') return;
    
    map[x][y] = '$';
    count++;

    flood(x - 1, y, baris, kolom);
    flood(x + 1, y, baris, kolom);
    flood(x, y - 1, baris, kolom);
    flood(x, y + 1, baris, kolom);
}

int main()
{
    int t; scanf("%d", &t);

    int baris, kolom;
    for (int i = 0; i < t; i++) {
        int startx = 0, starty = 0; count = 0;
        scanf("%d %d", &baris, &kolom); getchar();
        
        for (int j = 0; j < baris; j++) {
            for (int k = 0; k < kolom; k++) {
                scanf("%c", &map[j][k]);
                if (map[j][k] == 'S') {
                    startx = j;
                    starty = k;
                    map[j][k] = '.';
                }
            }
            getchar();
        }

        flood(startx, starty, baris, kolom);

        printf("Case #%d: %d\n", i+1, count - 1);
    }
}