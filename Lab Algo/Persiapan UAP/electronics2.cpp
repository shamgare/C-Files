#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct elec {
    char name[200];
    char type[200];
    int price;
    int stock;
} elec[1000];

int elecCount = 0;
int totSpace;

void swap(int a, int b)
{
    struct elec temp = elec[a];
    elec[a] = elec[b];
    elec[b] = temp;
}

int part(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[200];
    strcpy(pivot, elec[high].name);

    while (j < high) {
        if (strcmp(elec[j].name, pivot) < 0) {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);

    return i + 1;
}

void qs(int low, int high)
{
    if (low < high) {
        int pos = part(low, high);

        qs(pos, low - 1);
        qs(pos + 1, high);
    }
}

int binary(char* name)
{
    int left = 0;
    int right = elecCount - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(elec[mid].name, name) == 0) {
            return mid;
        }
        else if (strcmp(name, elec[mid].name) < 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

void importData()
{
    FILE* file = fopen("electronic.txt", "r");

    if (file == NULL) return;

    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%d#%d\n", elec[elecCount].name, elec[elecCount].type, &elec[elecCount].price, &elec[elecCount].stock);
        if (strcmp(elec[elecCount].type, "Small") == 0) {
            totSpace += elec[elecCount].stock * 1;
        }
        else if (strcmp(elec[elecCount].type, "Big") == 0) {
            totSpace += elec[elecCount].stock * 4;
        }
        else {
            totSpace += elec[elecCount].stock * 2;
        }
        
        elecCount++;
    }

    fclose(file);
}

void insertMenu()
{
    int choose;
    
    puts("Select the two option");
    puts("1. Insert new item");
    puts("2. Add existing item stock");
    puts("0. Back");
    do {
        printf(">> "); scanf("%d", &choose); getchar();
    } while (choose < 0 || choose > 2);

    qs(0, elecCount - 1);
    
    if (choose == 1) {
        if (totSpace == 150) {
            puts("There is no space left.");
        }
        else {
            char name[200];
            int flag = 0;
            do {
                printf("Input Item Name [5 - 25 chars | Unique]: ");
                scanf("%[^\n]", name); getchar();
            } while (binary(name) != -1 || strlen(name) < 5 || strlen(name) > 25);
            
            strcpy(elec[elecCount].name, name);
            
            do {
                printf("Input Item Type [Small | Medium | Big]: ");
                scanf("%s", elec[elecCount].type); getchar();
            } while (strcmp(elec[elecCount].type, "Small") != 0 && strcmp(elec[elecCount].type, "Big") != 0 && strcmp(elec[elecCount].type, "Medium") != 0);

            if (strcmp(elec[elecCount].type, "Small") == 0) {
                do {
                    printf("Input Item Price [max 200000]: ");
                    scanf("%d", &elec[elecCount].price); getchar();
                } while (elec[elecCount].price < 0 || elec[elecCount].price > 200000);

                do {
                    flag = 0;
                    
                    printf("Input Item Stock [more than 0]: ");
                    scanf("%d", &elec[elecCount].stock); getchar();
                    if (elec[elecCount].stock + totSpace > 150) {
                        flag = 1;
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace);
                    }
                } while (elec[elecCount].stock < 1 || flag == 1);

                totSpace += elec[elecCount].stock * 1;
            }
            else if (strcmp(elec[elecCount].type, "Big") == 0) {
                do {
                    printf("Input Item Price [max 10000000]: ");
                    scanf("%d", &elec[elecCount].price); getchar();
                } while (elec[elecCount].price < 0 || elec[elecCount].price > 10000000);

                do {
                    flag = 0;
                    
                    printf("Input Item Stock [more than 0]: ");
                    scanf("%d", &elec[elecCount].stock); getchar();
                    if (elec[elecCount].stock * 4 + totSpace > 150) {
                        flag = 1;
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace);
                    }
                } while (elec[elecCount].stock < 1 || flag == 1);

                totSpace += elec[elecCount].stock * 4;
            }
            else {
                do {
                    printf("Input Item Price [max %d]: ");
                    scanf("%d", &elec[elecCount].price); getchar();
                } while (elec[elecCount].price < 0 || elec[elecCount].price > 1500000);

                do {
                    flag = 0;
                    
                    printf("Input Item Stock [more than 0]: ");
                    scanf("%d", &elec[elecCount].stock); getchar();
                    if (elec[elecCount].stock * 2 + totSpace > 150) {
                        flag = 1;
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace);
                    }
                } while (elec[elecCount].stock < 1 || flag == 1);

                totSpace += elec[elecCount].stock * 2;
            }

            elecCount++;
        
            puts("Successfully inserted new item!");
        }
    }
    else if (choose == 2) {
        if (elecCount == 0) { printf("No electronics yet...\n"); return; }
        
        if (totSpace == 150) {
            puts("There is no space left."); 
        }
        else {
            qs(0, elecCount - 1);
            char name[200];
            int stock = 0;

            puts("===============================================================================");
            puts("| Electronic Name              | Electronic Type   | Price            | Stock |");
            puts("===============================================================================");
            for (int i = 0; i < elecCount; i++) {
                printf("| %-28s | %-17s | Rp.%-13d | %-5d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
            }
            puts("===============================================================================");

            do {
                printf("Input Electronic Name you want to add stock [Input \"back\" to back]: ");
                scanf("%[^\n]", name); getchar();
                if (strcmp(name, "back") == 0) return;
                if (binary(name) == -1) puts("Please input existing Electronic name!");
            } while (binary(name) == -1);

            int index = binary(name);
            int flag = 0;

            if (strcmp(elec[index].type, "Small") == 0) {
                do {
                    flag = 0;
                    
                    printf("Input how many stock you want to add: ");
                    scanf("%d", &stock); getchar();
                    
                    if (stock + totSpace > 150) {
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace);
                        flag = 1;
                    }
                } while (stock < 1 || flag == 1);

                elec[index].stock += stock;
                totSpace += stock * 1;
            }
            else if (strcmp(elec[index].type, "Big") == 0) {
                do {
                    flag = 0;
                    
                    printf("Input how many stock you want to add: ");
                    scanf("%d", &stock); getchar();
                    
                    if (stock * 4 + totSpace > 150) {
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace); 
                        flag = 1;
                    }
                } while (stock < 1 || flag == 1);

                elec[index].stock += stock;
                totSpace += stock * 4;
            }
            else {
                do {
                    flag = 0;
                    
                    printf("Input how many stock you want to add: ");
                    scanf("%d", &stock); getchar();
                    if (stock * 2 + totSpace > 150) {
                        flag = 1;
                        printf("Input stock is more than available Capacity [%d spaces]!\n", 150 - totSpace);
                    }
                } while (stock < 1 || flag == 1);

                elec[index].stock += stock;
                totSpace += stock * 2;
            }
            
            puts("Successfully added stock!");
        }
    }
    else if (choose == 0) {
        return;
    }
}

void viewAll()
{
    if (elecCount != 0) {
        qs(0, elecCount - 1);
    
        puts("================================================================================");
        puts("| Electronic Name              | Electronic Type   | Price            | Stock  |");
        puts("================================================================================");
        for (int i = 0; i < elecCount; i++) {
            printf("| %-28s | %-17s | Rp.%-13d | %-6d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
        }
        puts("================================================================================");
        printf("| %-67s | %-5.1lf%% |\n", "Used Capacity Percentage", ( (double) totSpace / 150) * 100);
        puts("================================================================================");
    }
    else {
        printf("No electronic yet...\n");
    }
}

void deleteMenu()
{
    if (elecCount == 0) { printf("No electronics yet...\n"); return; }
    
    qs(0, elecCount - 1);
    char name[200];

    puts("===============================================================================");
    puts("| Electronic Name              | Electronic Type   | Price            | Stock |");
    puts("===============================================================================");
    for (int i = 0; i < elecCount; i++) {
        printf("| %-28s | %-17s | Rp.%-13d | %-5d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
    }
    puts("===============================================================================");

    do {
        printf("Input Electronic Name you want to sell [Input \"back\" to back]: ");
        scanf("%[^\n]", name); getchar();
        if (strcmp(name, "back") == 0) return;
        if (binary(name) == -1) puts("Please input existing Electronic name!");
    } while (binary(name) == -1);

    int index = binary(name);
    int sell = 0;
    do {
        printf("Input item quantity you want to sell [1-%d]: ", elec[index].stock);
        scanf("%d", &sell); getchar();
    } while (sell < 1 || sell > elec[index].stock);

    puts("");
    puts("Successfully sold item!");
    puts("");
    puts("============================");
    puts("Transaction Details");
    puts("============================");
    printf("Electronic Name: %s\n", elec[index].name);
    printf("Electronic Type: %s\n", elec[index].type);
    printf("Quantity: %d\n", sell);
    printf("Total Price: %d\n", sell * elec[index].price);

    elec[index].stock -= sell;
    
    if (strcmp(elec[index].type, "Small") == 0) {
        totSpace -= sell * 1;
    }
    else if (strcmp(elec[index].type, "Big") == 0) {
        totSpace -= sell * 4;
    }
    else {
        totSpace -= sell * 2;
    }

    if (elec[index].stock == 0) {
        for (int i = index; i < elecCount - 1; i++) {
            elec[i] = elec[i + 1];
        }
        elecCount--;
    }
}

void exportData()
{
    FILE* file = fopen("electronic.txt", "w");

    for (int i = 0; i < elecCount; i++) {
        fprintf(file, "%s#%s#%d#%d\n", elec[elecCount].name, elec[elecCount].type, elec[elecCount].price, elec[elecCount].stock);
    }

    fclose(file);
}

int main()
{
    importData();
    int input;

    do {
        puts("Electronics 2.0!");
        puts("=========================");
        puts("1. Insert Electronic Stock"); 
        puts("2. View Electronic List"); 
        puts("3. Sell Electronic"); 
        puts("4. Exit");
        printf(">> "); scanf("%d", &input); getchar();

        switch (input) {
        case 1:
            insertMenu();
            printf("Press enter to continue....."); getchar();
            break;
        case 2:
            viewAll();
            printf("Press enter to continue....."); getchar();
            break;
        case 3:
            deleteMenu();
            printf("Press enter to continue....."); getchar();
            break;
        case 4:
            exportData();
            break;
        }

    } while (input != 4);
}

/*








*/