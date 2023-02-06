#include <stdio.h>

char map[105][105] = {};
int baris;
int kolom;
int count;

void pacmon(int x, int y, char old, char neww)
{
    if (map[x][y] == '*') {
        count++;
        map[x][y] = old;
        // printf("%d\n", count);
    }
    
    if (x < 0 || x >= baris || y < 0 || y >= kolom || map[x][y] != old) return;

    map[x][y] = neww;
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
        int x, y;
        for (int j = 0; j < baris; j++) {
            for (int k = 0; k < kolom; k++) {
                scanf("%c", &map[j][k]);
                if (map[j][k] == 'P'){
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
        
        printf("Case #%d: %d\n", i+1, count);
    }
}




/*
2
5 5
#####
#P..#
###.#
#*.*#
#####
5 5
#####
#P#*#
#####
#*.*#
#####

CASE SALAH
1
8 11
.##**...*.. bukan baris ini
*..*.***..#
#*##.*#....
*#..******#
.P.**#..#.# bukan baris ini
#.*....#... bukan baris ini
#.....#..#* bukan baris ini
.*#....**.. bukan baris ini


1
8 11
.##**...*..
*..*.***..#
#*##.*#....
*#..******#
.P.**#..#.#
#.*....#...
#.....#..#*
.*#....**..

*/