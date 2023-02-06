#include <stdio.h>

char map[101][101];
int count[200];

void game(int x, int y, int size)
{
    if (x < 0 || y < 0 || x >= size || y >= size || map[x][y] == '#') return;

    if (map[x][y] >= 97 && map[x][y] <= 122) count[map[x][y]]++;
    map[x][y] = '#';
    
    game(x + 1, y, size);
    game(x - 1, y, size);
    game(x, y + 1, size);
    game(x, y - 1, size);
}

int main()
{
    int size; scanf("%d", &size); getchar();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    game(0, 0, size);

    for (int i = 0; i < 26; i++) {
        if (count[i + 97] > 0) printf("%c %d\n", i + 97, count[i + 97]);
    }
}