#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <cstring>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>
#define ll long long
#define ld long double
using namespace std;

// int file()
// {
//     char line[255];

//     // FILE * fpointer = fopen("testing.txt", "w");
//     // fprintf(fpointer, "PPTI 16\nPPTI 15\nPPTI 14\n");
//     // fclose(fpointer);

//     FILE * fpointer = fopen("testing.txt", "r");
//     fgets(line, 255, fpointer);
//     printf("%s", line);
//     fgets(line, 255, fpointer);
//     printf("%s", line);
//     fgets(line, 255, fpointer);
//     printf("%s", line);
    
//     fclose(fpointer);
// }

char str[] = "Hello.";
int random()
{
    srand(time(0));
    //char vokal[6]={"aiueo"};
    char az[63] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
    char id[11] = {};
    //int i = 0;
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<=9; j++) {
            id[j] = az[rand() % 63];
        }
        printf("%s\n", id);
        id[11] = {};
    }

    // printf("|");
    // while (i<10) {
    //     printf("%c|", rand() % 26 + 65); //huruf kapital random
    //     printf("%d|", rand() % 10);      //angka random
    //     printf("%c|", rand() % 26 + 97); //huruf kecil random
    //     //printf("%c|", vokal[rand() % 5]); //huruf vokal
    //     i++;
    // }
}

// void alpha()
// {
//     float check, s;
//     scanf("%c", &s);
//     //check = isalpha(s);
//     //printf("check = %d\n", check);
//     printf("S = %f\n", s);
// }

void atoint()
{
    char a[100] = {"12345"};
    int x = atoi(a);
    printf("%d", x);

}

int main()
{
    //system("cls");
    //tes();
    //file();
    //random();
    //alpha();
    //atoint();

    return 0;
}
