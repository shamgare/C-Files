#include <stdio.h>

int grid[50][50] = {};
int baris;
int kolom;
int count;

void game(int x, int y, int old, int neww)
{
    if (x < 0 || x >= baris || y < 0 || y >= kolom || grid[x][y] != old) return;

    grid[x][y] = neww; count++;
    game(x+1, y, old, neww);
    game(x, y+1, old, neww);
    game(x-1, y, old, neww);
    game(x, y-1, old, neww);
}

int main()
{
    scanf("%d %d", &baris, &kolom);
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);
    
    int neww = 8;
    int old = grid[x][y];
    game(x, y, old, neww);

    printf("%d\n", count);

    return 0;
}