#include <stdio.h>
#include <string.h>

int main()
{
    char kata[1000050];
    char huruf[200];
    int countA = 0, countI = 0, countU = 0, countE = 0, countO = 0;
    int vokal = 0, kons = 0;
    scanf("%[^\n]", &kata);

    for (int i = 0; i<strlen(kata); i++) {
        if (kata[i] == 'a') countA++;
        if (kata[i] == 'i') countI++;
        if (kata[i] == 'u') countU++;
        if (kata[i] == 'e') countE++;
        if (kata[i] == 'o') countO++;
        if (kata[i] != ' ' && kata[i] != 'a' && kata[i] != 'i' && kata[i] != 'u' && kata[i] != 'e' && kata[i] != 'o') {
            if (huruf[kata[i]] == 0) {
                kons++;
                huruf[kata[i]] = 1;
            }
        }
    }
    if (countA>=1) vokal++;
    if (countI>=1) vokal++;
    if (countU>=1) vokal++;
    if (countE>=1) vokal++;
    if (countO>=1) vokal++;

    printf("Vocal: %d\n", vokal);
    printf("Consonant: %d\n", kons);
    
    return 0;
}