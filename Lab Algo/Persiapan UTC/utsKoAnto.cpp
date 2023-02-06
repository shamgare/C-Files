#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int input = 0;
    int lastIndex = 0;
    char az[63] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"};
    char name[255][255] = {};
    char type[255][255] = {};
    char price[255][255] = {};
    char idTetap[255][11] = {};

    do {

        printf("\n");
        puts(" _");
        puts("| |");
        puts("| |");
        puts("| |      ___  _ _ _  ___  ___  ____ ");
        puts("| |     / _ \\| | | |/___)/ _ \\|  _ \\");
        puts("| |____| |_| | | | |___ | |_| | | | |");
        puts("|_______)___/\\_____(___/ \\___/|_| |_|");
        printf("\n");
        
        if (lastIndex == 0) {
            printf("No products....\n");
        } else {
            puts("+-----+------------+-----------------------------+--------------+-----------------------+");
            puts("| No. | ID         | Name                        | Type         | Price                 |");
            puts("+-----+------------+-----------------------------+--------------+-----------------------+");

            for (int i = 0; i < lastIndex; i++) {
                printf("| %.3d | ", i+1);
                printf("%s", idTetap[i]);
                printf(" | %-27s | %-12s | IDR %17s |\n", name[i], type[i], price[i]);
            }

            puts("+-----+------------+-----------------------------+--------------+-----------------------+");
        }

        printf("\n");
        printf("1. Create Product\n");
        printf("2. Update Product\n");
        printf("3. Remove Product\n");
        printf("4. Exit\n");
        printf(">> "); scanf("%d", &input); getchar();

        if (input == 1) {

            puts("+-------------+");
            puts("| Create Menu |");
            puts("+-------------+");
            puts("");
            
            do {
                printf("Product Name [not empty]: ");
                scanf("%[^\n]", name[lastIndex]);
                getchar();
                if (strcmp(name[lastIndex], "\n") == 1) break;
            } while (strcmp(name[lastIndex], "\n"));

            do {
                printf("Product Type [Food | Beverage | Cosmetic | Others] (case ensitive): ");
                scanf("%s", type[lastIndex]);
                getchar();
                if (strcmp(type[lastIndex], "Food") == 0 || strcmp(type[lastIndex], "Beverage") == 0 || strcmp(type[lastIndex], "Others") == 0 || strcmp(type[lastIndex], "Cosmetic") == 0) break;
            } while (strcmp(type[lastIndex], "Food") == 1 || strcmp(type[lastIndex], "Beverage") == 1 || strcmp(type[lastIndex], "Others") == 1 || strcmp(type[lastIndex], "Cosmetic") == 1);

            int x = 0, check;
            do {
                check = 0;
                printf("Product Price [more than 0]: ");
                scanf("%s", price[lastIndex]);
                getchar();
                x = atoi(price[lastIndex]);
                for (int j = 0; j<strlen(price[lastIndex]); j++) {
                    if (isalpha(price[lastIndex][j])) {
                        check++;
                    }
                }
            } while (x<=0 || check > 0);

            printf("Create product success! "); getchar();

            for (int k = 0; k < 10; k++) {
                idTetap[lastIndex][k] = az[rand() % 63];
            }
            lastIndex++;
            //system("cls");
            
        } else if (input == 2) {
            int num;
            if (lastIndex == 0) {
                system("cls");
            } else {

                do {
                    printf("Input Product Number [1..%d]: ", lastIndex);
                    scanf("%d", &num);
                    getchar();
                } while (num <= 0 || num > lastIndex);

                do {
                    printf("Product name [not empty]: ");
                    scanf("%[^\n]", name[num-1]);
                    getchar();
                    if (strcmp(name[num-1], "\n") == 1) break;
                } while (strcmp(name[num-1], "\n"));

                do {
                    printf("Product Type [Food | Beverage | Cosmetic | Others] (case ensitive): ");
                    scanf("%s", type[num-1]);
                    getchar();
                    if (strcmp(type[num-1], "Food") == 0 || strcmp(type[num-1], "Beverage") == 0 || strcmp(type[num-1], "Others") == 0 || strcmp(type[num-1], "Cosmetic") == 0) break;
                } while (strcmp(type[num-1], "Food") == 1 || strcmp(type[num-1], "Beverage") == 1 || strcmp(type[num-1], "Others") == 1 || strcmp(type[num-1], "Cosmetic") == 1);

                int x = 0, check;
                do {
                    check = 0;
                    printf("Product Price [more than 0]: ");
                    scanf("%s", price[num-1]);
                    getchar();
                    x = atoi(price[num-1]);
                    for (int j = 0; j<strlen(price[num-1]); j++) {
                        if (isalpha(price[num-1][j])) {
                            check++;
                        }
                    }
                } while (x<=0 || check > 0);

                printf("Update product success! "); getchar();
            }
        } else if (input == 3) {
            int del = 0;
            if (lastIndex == 0) {
                system("cls");
            } else {

                do {
                    printf("Input Product Number [1..%d]: ", lastIndex);
                    scanf("%d", &del);
                    getchar();
                } while (del <= 0 || del > lastIndex);
                
                //disini
                for (int k = del-1; k<lastIndex-1; k++) {
                    strcpy(idTetap[k], idTetap[k+1]);
                    strcpy(name[k], name[k+1]);
                    strcpy(type[k], type[k+1]);
                    strcpy(price[k], price[k+1]);
                }

				lastIndex--;
                printf("Delete product success! "); getchar();
            }
        } else if (input == 4) {
            printf("Thanks for using this app :D\n");
        } else {
            system("cls");
        }
    } while (input != 4);

    return 0;
}