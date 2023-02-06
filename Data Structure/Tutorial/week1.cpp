#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pc {
    char moth[30];
    char proc[30];
    char vga[30];
    int ram;
    float price;
} pc[50];

int pcCount = 0;

void displayMenu()
{
    if (pcCount == 0) { printf("No data to display..."); getchar(); return; }
    
    for (int i = 0; i < pcCount; i++) {
        printf("| %-2d | %-10s | %-10s | %-10s | %-10d | %-10.2f |\n", i+1, pc[i].moth, pc[i].proc, pc[i].vga, pc[i].ram, pc[i].price);
    }
}

void insertMenu()
{
    printf("Enter motherboard name: ");
    scanf("%[^\n]", pc[pcCount].moth); getchar();
    printf("Enter processor name: ");
    scanf("%[^\n]", pc[pcCount].proc); getchar();
    printf("Enter vga name: ");
    scanf("%[^\n]", pc[pcCount].vga); getchar();
    printf("Enter ram size: ");
    scanf("%d", &pc[pcCount].ram); getchar();
    printf("Enter prize: ");
    scanf("%f", &pc[pcCount].price); getchar();

    pcCount++;
}

void updateMenu()
{
    
}

void deleteMenu()
{
    
}

int main()
{
    int input;
    do {
        system("cls");
        puts("PC DATA");
        puts("====================");
        puts("1. Display");
        puts("2. Insert");
        puts("3. Update");
        puts("4. Delete");
        puts("5. Exit");
        printf("Choose >> "); scanf("%d", &input); getchar();

        switch (input) {
        case 1:
            displayMenu();
            printf("Press enter to continue....."); getchar();
            break;
        case 2:
            insertMenu();
            printf("Press enter to continue....."); getchar();
            break;
        case 3:
            updateMenu();
            printf("Press enter to continue....."); getchar();
            break;
        case 4:
            deleteMenu();
            printf("Press enter to continue....."); getchar();
            break;
        default:
            printf("Thanks!");
            break;
        }
    } while (input != 5);
}