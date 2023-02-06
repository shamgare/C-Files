#include <stdio.h>

int board[8][8];
int board2[8][8];
int limit;
int flag;

void horse1(int x, int y, int move)
{
    if (x < 0 || y < 0 || x > 7 || y > 7 || move > limit || board[x][y]) return;

    board[x][y] = 1;
    
    horse1(x + 1, y + 2, move + 1);
    horse1(x - 1, y + 2, move + 1);
    
    horse1(x + 2, y + 1, move + 1);
    horse1(x + 2, y - 1, move + 1);
    
    horse1(x + 1, y - 2, move + 1);
    horse1(x - 1, y - 2, move + 1);
    
    horse1(x - 2, y + 1, move + 1);
    horse1(x - 2, y - 1, move + 1);
}

void horse2(int x, int y, int move)
{
    if (x < 0 || y < 0 || x > 7 || y > 7 || move > 6 || board2[x][y]) return;

    board2[x][y] = 1;
    
    if (board[x][y] == 1) {
        flag = 1;
        return;
    }
    
    horse2(x + 1, y + 2, move + 1);
    horse2(x - 1, y + 2, move + 1);
    
    horse2(x + 1, y - 2, move + 1);
    horse2(x - 1, y - 2, move + 1);
    
    horse2(x + 2, y + 1, move + 1);
    horse2(x + 2, y - 1, move + 1);
    
    horse2(x - 2, y + 1, move + 1);
    horse2(x - 2, y - 1, move + 1);
}

int main()
{
    int kasus; scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = 0;
                board2[i][j] = 0;
            }
        }
        flag = 0;

        scanf("%d", &limit); getchar();

        char one[5] = {};
        char two[5] = {};
        int x1, x2, y1, y2;
        
        scanf("%s %s", one, two); getchar();
        x1 = one[0] - 65;
        y1 = 7 - (one[1] - 49);

        x2 = two[0] - 65;
        y2 = 7 - (two[1] - 49);

        horse1(x1, y1, 0);
        horse2(x2, y2, 0);

        if (flag == 1) printf("YES\n");
        else printf("NO\n");
    }
}

/*

// for (int i = 0; i < 8; i++) {
//     for (int j = 0; j < 8; j++) {
//         printf("%d", board[i][j]);
//     }
//     printf("\n");
// }



*/