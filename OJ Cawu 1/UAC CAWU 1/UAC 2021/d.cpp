#include <stdio.h>

int count = 0;
char map[105][105] = {};

void game(int x, int y, int size)
{
    if (map[x][y] == '.') count++;
    if (x < 0 || x >= size || y < 0 || y >= size || map[x][y] != '.') return;
    map[x][y] = '#';

    game(x+1, y, size);
    game(x, y+1, size);
    game(x-1, y, size);
    game(x, y-1, size);
}

void sort(int kingdom, int* posX, int* posY, char* alphabet)
{
    //sort alphabet
    for (int i = 0; i < kingdom - 1; i++) {
        for (int j = i+1; j < kingdom; j++) {
            if (alphabet[i] > alphabet[j]) {
                int temp1 = posX[i];
                int temp2 = posY[i];
                char alpha = alphabet[i];
                posX[i] = posX[j];
                posY[i] = posY[j];
                alphabet[i] = alphabet[j];
                posX[j] = temp1;
                posY[j] = temp2;
                alphabet[j] = alpha;
            }
        }
    }
}

int main()
{
    int size, kingdom; scanf("%d %d", &size, &kingdom); getchar();
    int posX[30], posY[30]; int index = 0;
    char alphabet[kingdom + 1] = {};

    // scan
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%c", &map[i][j]);
            if (map[i][j] >= 97 && map[i][j] <= 122) { 
                posX[index] = i; posY[index] = j;
                alphabet[index] = map[i][j];
                index++;
                map[i][j] = '.';
            }
        }
        getchar();
    }

    sort(kingdom, posX, posY, alphabet);

    // masuk game
    for (int i = 0; i < kingdom; i++) {
        game(posX[i], posY[i], size);
        printf("%c %d\n", alphabet[i], count);
        count = 0;
    }
}



/*
5 4
#####
#a#b#
##.##
#.c.#
#####
7 4
#######
#a...##
#####.#
#.b#..#
###..d#
#c.#..#
#######

*/