#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main () {
    srand(time(0));
    int input;
    char id[255][255] = {};
    int lastIndex = 0;
    char name[255][255] = {};
    int price[255] = {};
    char disc[11] = "1110000000";

    do {
        printf("\n");
        puts("Electronics!");
        puts("=================");
        puts("1. Insert Electronic Stock");
        puts("2. Update Electronic");
        puts("3. Sell Electronic");
        puts("4. Exit");
        printf(">> "); scanf("%d", &input); getchar();

        if (input == 1) {

            int x = 0;
            do {
                x = 0;
                printf("Input item ID: ");
                scanf("%s", id[lastIndex]);
                getchar();

                for (int i = 0; i < strlen(id[lastIndex]); i++) {
                    if (isalpha(id[lastIndex][i])) {
                        x++;
                    }
                }
            } while ( strlen(id[lastIndex]) != 3 || x != 0);

            do {
                printf("Input item name [5-25 chars]: ");
                scanf("%[^\n]", name[lastIndex]);
                getchar();
            } while (strlen(name[lastIndex]) < 5 || strlen(name[lastIndex]) > 25);

            do {
                printf("Input item price [not more than 5M]: ");
                scanf("%d", &price[lastIndex]);
                getchar();
            } while (price[lastIndex] <= 0 || price[lastIndex] > 5000000);

            printf("Item successfully inserted!\n");
            printf("Press enter to continue...");
            getchar();

            lastIndex++;
            // x selalu di reset, janlup pakai index, isalpha di loop, isalpha masukin if

        } else if (input == 2) {
            int choice = 0;
            if (lastIndex == 0) {
                printf("There is no item yet...\n");
            } else {
                puts("=============================================================");
                puts("| No. | ID     | Name                      | Price          |");
                puts("=============================================================");
                for (int i = 0; i < lastIndex; i++) {
                    printf("| %-3d | ETC%s | %-25s | Rp. %-10.2f |\n", i+1, id[i], name[i], (float) price[i]);
                }
                puts("=============================================================");

                do {
                    printf("Which item you want to update? [0 to exit] [1...%d]: ", lastIndex);
                    scanf("%d", &choice);
                    getchar();
                } while (choice < 0 || choice > lastIndex);

                if(choice==0) continue;

                int x = 0;
                do {
                    x = 0;
                    printf("Input item ID: ");
                    scanf("%s", id[choice-1]);
                    getchar();

                    for (int i = 0; i < strlen(id[choice-1]); i++) {
                        if (isalpha(id[choice-1][i])) {
                            x++;
                        }
                    }
                } while ( strlen(id[choice-1]) != 3 || x != 0);

                do {
                    printf("Input item name [5-25 chars]: ");
                    scanf("%[^\n]", name[choice-1]);
                    getchar();
                } while (strlen(name[choice-1]) < 5 || strlen(name[choice-1]) > 25);

                do {
                    printf("Input item price [not more than 5M]: ");
                    scanf("%d", &price[choice-1]);
                    getchar();
                } while (price[choice-1] <= 0 || price[choice-1] > 5000000);

                printf("Item successfully updated!\n");
                printf("Press enter to continue...");
                getchar();
            }
        } else if (input == 3) {
            int del = 0;
            char chance = 0;
            if (lastIndex == 0) {
                printf("There is no item yet...\n");
                continue;
            } else {
                puts("=============================================================");
                puts("| No. | ID     | Name                      | Price          |");
                puts("=============================================================");
                for (int i = 0; i < lastIndex; i++) {
                    printf("| %-3d | ETC%s | %-25s | Rp. %-10.2f |\n", i+1, id[i], name[i], (float) price[i]);
                }
                puts("=============================================================");
            }

            printf("Which item do you want to sell? [0 to exit] [1...%d]: ", lastIndex);
            scanf("%d", &del);
            getchar();

            if (del == 0) {
                continue;
            } else {
                chance = disc[rand() % 11];
                char yn[4] = {};
                int x = 0;

                if (chance == '1') {
                    puts("##########################");
                    puts("Customer got discount 25%!");
                    puts("##########################");
                    printf("\n");

                    price[del-1] *= 0.75;
                }

                printf("ETC%s Item Detail\n", id[del-1]);
                puts("=============================");
                printf("Item Name: %s\n", name[del-1]);
                printf("Item Price: %.2f\n", (float) price[del-1]);

                do {
                    x = 0;
                    printf("Are you sure you want to sell this? [yes|no]: ");
                    scanf("%s", yn);
                    getchar();
                    if (strcmp(yn, "yes") == 0 || strcmp(yn, "no") == 0) {
                        x++;
                    }
                } while (x == 0);

                if (strcmp(yn, "no") == 0) {
                    printf("Cancel selling!\n");
                } else {
                    printf("Item successfully sold!\n");

                    for (int k = del-1; k<lastIndex-1; k++) {
                        strcpy(id[k], id[k+1]);
                        strcpy (name[k], name[k+1]);
                    }
                    for (int j = del-1; j<lastIndex;j++) {
                        price[j] = price[j+1];
                    }
                    lastIndex--;
                }
                printf("Press enter to continue..."); getchar();
            }
        } else if (input == 4) {
            printf("Thank you for using this app :D\n");
        } else {
            system("cls");
        }
    } while (input != 4);

    return 0;
}