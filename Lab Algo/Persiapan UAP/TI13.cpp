#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct games {
    char code[200];
    char name[200];
    char type[50];
    int price;
    int quan;
} games[100];
int gameCount = 0;

int cartCount = 0;

int mobaCount = 0;
int fpsCount = 0;
int othCount = 0;

int index = 1;
int flag2 = 0;

void swap(int a, int b)
{
    struct games temp = games[a];
    games[a] = games[b];
    games[b] = temp;
}

int part2(struct games cart[], int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[100];
    strcpy(pivot, cart[high].code);

    while (j < high) {
        if (strcmp(pivot, cart[j].code) >= 0) {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i+1, high);

    return i+1;
}

void qs2(struct games cart[], int low, int high)
{
    if (low < high) {
        int pos = part2(cart, low, high);

        qs2(cart, low, pos-1);
        qs2(cart, pos+1, high);
    }
}

int part(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[100];
    strcpy(pivot, games[high].code);

    while (j < high) {
        if (strcmp(pivot, games[j].code) >= 0) {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i+1, high);

    return i+1;
}

void qs(int low, int high)
{
    if (low < high) {
        int pos = part(low, high);

        qs(low, pos-1);
        qs(pos+1, high);
    }
}

int search(struct games cart[], int left, int right, char* code)
{
    while (left <= right) {
        int mid = (left + right) / 2;
        printf("%s %s\n", code, cart[mid].code);
        if (strcmp(code, cart[mid].code) == 0) {
            return mid;
        } else if (strcmp(code, cart[mid].code) < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void importData()
{
    FILE* file = fopen("games.txt", "r");
    if (file == NULL) return;

    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%[^#]#%d#%d\n", games[gameCount].code, games[gameCount].name, games[gameCount].type, &games[gameCount].price, &games[gameCount].quan);
        if (strcmp(games[gameCount].code, "") == 0) break;
        if (strcmp(games[gameCount].type, "MOBA") == 0) mobaCount++;
        else if (strcmp(games[gameCount].type, "FPS") == 0) fpsCount++;
        else if (strcmp(games[gameCount].type, "Others") == 0) othCount++;
        gameCount++;
    }
    
    fclose(file);
}

void random()
{
    char temp1, temp2, temp3, temp4;
    temp1 = games[gameCount].type[0];
    temp2 = games[gameCount].type[1];
    temp3 = games[gameCount].type[2];

    if (temp1 >= 97 && temp1 <= 122) temp1 -= 32;
    if (temp2 >= 97 && temp2 <= 122) temp2 -= 32;
    if (temp3 >= 97 && temp3 <= 122) temp3 -= 32;

    temp4 = games[gameCount].name[strlen(games[gameCount].name) - 1];
    if (temp4 >= 97 && temp4 <= 122) temp4 -= 32;

    sprintf(games[gameCount].code, "%c%c%c%d%d%d%d%c", temp1, temp2, temp3, rand() % 10, rand() % 10, rand() % 10, rand() % 10, temp4);
}

void addMenu()
{
    system("cls");
    puts("1. MOBA");
    puts("2. FPS");
    puts("3. Others"); puts("");

    int pick1 = 0;
    do {
        printf("Choose Game Type [1-3]: ");
        scanf("%d", &pick1); getchar();
    } while (pick1 < 1 || pick1 > 3);

    if (pick1 == 1) {
        strcpy(games[gameCount].type, "MOBA"); mobaCount++;
    } else if (pick1 == 2) {
        strcpy(games[gameCount].type, "FPS"); fpsCount++;
    } else {
        strcpy(games[gameCount].type, "Others"); othCount++;
    }

    do {
        printf("Insert Game Name [3-20 chars]: ");
        scanf("%[^\n]", games[gameCount].name); getchar();
    } while (strlen(games[gameCount].name) < 3 || strlen(games[gameCount].name) > 20);

    do {
        printf("Insert Game Price [10000-10000000]: ");
        scanf("%d", &games[gameCount].price); getchar();
    } while (games[gameCount].price < 10000 || games[gameCount].price > 10000000);

    do {
        printf("Insert Game Quantity [1-200000]: ");
        scanf("%d", &games[gameCount].quan); getchar();
    } while (games[gameCount].quan < 1 || games[gameCount].quan > 200000);

    random();

    printf("%s\n", games[gameCount].code);
    printf("Game Name : %s\n", games[gameCount].name);
    printf("Game Type : %s\n", games[gameCount].type);
    printf("Game Price : %d\n", games[gameCount].price);
    printf("Game Quantity : %d\n", games[gameCount].quan);

    gameCount++;
}

void viewAll()
{
    system("cls");
    qs(0, gameCount - 1);

    puts("1. MOBA");
    puts("2. FPS");
    puts("3. Others");
    puts("4. All"); puts("");

    int pick;
    do {
        printf("View Type [1 - 4 | 0 to exit] : ");
        scanf("%d", &pick); getchar();
        if (pick == 0) break;
    } while (pick < 1 || pick > 4);

    if (pick == 0) return;
    if (gameCount == 0) { puts("No game registered..."); return; }

    if (pick == 1) {
        if (mobaCount == 0) puts("No game registered...");
        else {
            int index = 1;
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "MOBA") == 0) printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
            }
            puts("=====================================================================================");
        }
    } else if (pick == 2) {
        if (fpsCount == 0) puts("No game registered...");
        else {
            int index = 1;
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "FPS") == 0) printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
            }
            puts("=====================================================================================");
        }
    } else if (pick == 3) {
        if (othCount == 0) puts("No game registered...");
        else {
            int index = 1;
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "Others") == 0) printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
            }
            puts("=====================================================================================");
        }
    } else if (pick == 4) {
        puts("=====================================================================================");
        puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
        puts("=====================================================================================");
        for (int i = 0; i < gameCount; i++) {
            printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", i+1, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
        }
        puts("=====================================================================================");
    }
}

void purchase1(int pick)
{
    flag2 = 0;

    if (pick == 1 && mobaCount == 0) {
        puts("No game registered..."); {flag2 = 1; return;}
    } else if (pick == 2 && fpsCount == 0) {
        puts("No game registered..."); {flag2 = 1; return;}
    } else if (pick == 3 && othCount == 0) {
        puts("No game registered..."); {flag2 = 1; return;}
    } else {
        if (pick == 1) {
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "MOBA") == 0 && games[i].quan != 0) {
                    printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
                }
            }
            puts("=====================================================================================");
        } else if (pick == 2) {
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "FPS") == 0 && games[i].quan != 0) {
                    printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
                }
            }
            puts("=====================================================================================");
        } else if (pick == 3) {
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (strcmp(games[i].type, "Others") == 0 && games[i].quan != 0) {
                    printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
                }
            }
            puts("=====================================================================================");
        } else if (pick == 4) {
            puts("=====================================================================================");
            puts("| No.  | Code       | Name                   | Type      | Price       | Quantity   |");
            puts("=====================================================================================");
            for (int i = 0; i < gameCount; i++) {
                if (games[i].quan != 0) {
                    printf("| %-4d | %-10s | %-22s | %-9s | %-11d | %-10d |\n", index++, games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
                }
            }
            puts("=====================================================================================");
        }
    }
}

void purchase2(struct games cart[], int pick)
{
    int choose = 0;
    int quan = 0;

    if (pick == 1) {
        //MOBA
        do {
            printf("Input No [1 - %d | 0 to exit]: ", index - 1);
            scanf("%d", &choose); getchar();
        } while (choose < 1 || choose > index - 1);

        choose += fpsCount - 1;

        do {
            printf("Input Quantity [1 - %d]: ", games[choose].quan);
            scanf("%d", &quan); getchar();
        } while (quan < 1 || quan > games[choose].quan);
        
        games[choose].quan -= quan;
    } else if (pick == 2) {
        //FPS
        do {
            printf("Input No [1 - %d | 0 to exit]: ", index - 1);
            scanf("%d", &choose); getchar();
        } while (choose < 1 || choose > index - 1);

        choose -= 1;

        do {
            printf("Input Quantity [1 - %d]: ", games[choose].quan);
            scanf("%d", &quan); getchar();
        } while (quan < 1 || quan > games[choose].quan);
        
        games[choose].quan -= quan;
    } else if (pick == 3) {
        //OTHERS
        do {
            printf("Input No [1 - %d | 0 to exit]: ", index - 1);
            scanf("%d", &choose); getchar();
        } while (choose < 1 || choose > index - 1);

        choose += fpsCount + mobaCount - 1;

        do {
            printf("Input Quantity [1 - %d]: ", games[choose].quan);
            scanf("%d", &quan); getchar();
        } while (quan < 1 || quan > games[choose].quan);
        
        games[choose].quan -= quan;
    } else if (pick == 4) {
        do {
            printf("Input No [1 - %d | 0 to exit]: ", index - 1);
            scanf("%d", &choose); getchar();
        } while (choose < 1 || choose > index - 1);

        choose -= 1;

        do {
            printf("Input Quantity [1 - %d]: ", games[choose].quan);
            scanf("%d", &quan); getchar();
        } while (quan < 1 || quan > games[choose].quan);
        
        games[choose].quan -= quan;
    }

    strcpy(cart[cartCount].name, games[choose].name);
    strcpy(cart[cartCount].code, games[choose].code);
    strcpy(cart[cartCount].type, games[choose].type);
    cart[cartCount].price = games[choose].price;
    cart[cartCount].quan = quan;
    cartCount++;

    if (games[choose].quan == 0) {
        for (int i = choose; i < gameCount - 1; i++) {
            swap(i, i+1);
        }
        if (pick == 1) {
            mobaCount--;
        } else if (pick == 2) {
            fpsCount--;
        } else if (pick == 3) {
            othCount--;
        }
        gameCount--;
    }

    puts("Item added to cart!");
}

void purchaseBill(struct games cart[])
{
    system("cls");

    int tot = 0; int check = 0;

    qs2(cart, 0, cartCount - 1);
    for (int i = 0; i < cartCount - 1; i++) {
        if (strcmp(cart[i].code, cart[i+1].code) == 0) {
            check++;
        }
    }
    puts("STIIMM");
    puts("============");
    printf("Games Bought: %d\n", cartCount - check);
    for (int i = 0; i < cartCount; i++) {
        printf("Game Name: %s\n", cart[i].name);
        printf("\t%d x %d : %d\n", cart[i].quan, cart[i].price, cart[i].quan * cart[i].price);
        tot += cart[i].quan * cart[i].price;
    }
    puts("");
    puts("=============================================");
    printf("Total Price\t: %d\n", tot);
    printf("Tax\t\t: %d\n", tot / 10);
    printf("Grand Total\t: %d\n", tot + (tot / 10));
    puts("=============================================");
    puts("Thanks For Your Purchase!");
    puts("");
}

void purchaseMenu()
{
    system("cls");
    qs(0, gameCount - 1);

    struct games cart[20];
    cartCount = 0;

    if (gameCount == 0) {
        puts("No game registered on STIIMM"); return;
    } else {
        char yesno[4];
        int mCartCount = 0;
        int fCartCount = 0;
        int oCartCount = 0;

        do {
            if (gameCount == 0) { puts("No game available"); break; }
            puts("1. MOBA");
            puts("2. FPS");
            puts("3. Others");
            puts("4. All"); puts("");

            int pick;
            do {
                printf("Choose a type to view [1-4] : ");
                scanf("%d", &pick); getchar();
            } while (pick < 1 || pick > 4);

            // hell
            index = 1;
            purchase1(pick);
            if (flag2 == 0) purchase2(cart, pick);

            do {
                printf("Do you want to purchase more games? [Yes | No (case sensitive)] : ");
                scanf("%s", &yesno); getchar();
            } while (strcmp(yesno, "Yes") != 0 && strcmp(yesno, "No") != 0);

        } while (strcmp(yesno, "Yes") == 0);

        purchaseBill(cart);
    }
}

void exportData()
{
    FILE* file = fopen("games.txt", "w");

    for (int i = 0; i < gameCount; i++) {
        fprintf(file, "%s#%s#%s#%d#%d\n", games[i].code, games[i].name, games[i].type, games[i].price, games[i].quan);
    }
    
    fclose(file);
}

int main()
{
    int input = 0;
    srand(time(0));
    importData();

    do {
        puts("STIIMM");
        puts("==============");
        puts("1. Add Game");
        puts("2. View Game");
        puts("3. Purchase Game");
        puts("4. Exit");
        printf("Choose >> "); scanf("%d", &input); fflush(stdin);
        
        if (input == 1) {
            addMenu();
            printf("Press enter to continue...."); getchar();
        } else if (input == 2) {
            viewAll();
            printf("Press enter to continue...."); getchar();
        } else if (input == 3) {
            purchaseMenu();
            printf("Press enter to continue...."); getchar();
        } else if (input == 4) {
            exportData();
            puts("Thanks for using this app!");
        } else {
            puts("Please input a valid number!");
            printf("Press enter to continue...."); getchar();
        }
    } while (input != 4);
}