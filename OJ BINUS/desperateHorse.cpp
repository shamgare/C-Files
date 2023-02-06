#include <stdio.h>

int board[8][8];
int selesai;
int move = 0;

void func(int x, int y, int endX, int endY, int move)
{
    if (x < 0 || y < 0 || x > 7 || y > 7 || move > 6) return;
    if (board[x][y]) {
        if (x == endX && y == endY) {
            if (selesai > move) {
                selesai = move;
            }
        }
        return;
    }
    board[x][y] = 1;

    func(x + 2, y - 1, endX, endY, move + 1);
    func(x + 2, y + 1, endX, endY, move + 1);
    
    func(x - 2, y - 1, endX, endY, move + 1);
    func(x - 2, y + 1, endX, endY, move + 1);
    
    func(x + 1, y + 2, endX, endY, move + 1);
    func(x - 1, y + 2, endX, endY, move + 1);
    
    func(x + 1, y - 2, endX, endY, move + 1);
    func(x - 1, y - 2, endX, endY, move + 1);
}

int main()
{
    int kasus; scanf("%d", &kasus);
    for (int i = 0; i < kasus; i++) {
        selesai = 1000;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                board[j][k] = 0;
            }
        }
        
        char start[3] = {}, end[3] = {};
        scanf("%s %s", start, end);

        int startX, startY, endX, endY;
        startY = start[0] - 65;
        startX = 8 - (start[1] - 48);
        endY = end[0] - 65;
        endX = 8 - (end[1] - 48);

        func(startX, startY, endX, endY, 0);
        printf("%d\n", selesai);
    }
}





// A7 E7
// 07 47
// 1 0, 1 4

// printf("%d %d | %d %d\n", startX, startY, endX, endY);