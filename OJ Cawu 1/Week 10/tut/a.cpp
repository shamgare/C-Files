#include <stdio.h>
#include <string.h>

struct matkul {
    char code[200];
    char nama[200];
    int credit;
} matkul[1010];

int main()
{
    int kasus; scanf("%d", &kasus); getchar();
    for (int i = 0; i < kasus; i++) {
        scanf("%s", matkul[i].code); getchar();
        scanf("%[^\n]", matkul[i].nama);
        scanf("%d", &matkul[i].credit);
    }
    int query; scanf("%d", &query); getchar();
    for (int i = 0; i < query; i++) {
        int index; scanf("%d", &index); getchar();
        printf("Query #%d:\n", i+1);
        printf("Code: %s\n", matkul[index - 1].code);
        printf("Name: %s\n", matkul[index - 1].nama);
        printf("Credits: %d\n", matkul[index - 1].credit);
    }
}
/*
3
COMP6047
Algorithm and Programming
6
COMP6056
Program Design Methods
4
MATH6025
Discrete Mathematics
4
3
3
2
1



*/