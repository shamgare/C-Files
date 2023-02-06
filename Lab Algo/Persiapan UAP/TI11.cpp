#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// random fried rice shop

struct order {
    char name[150];
    char rice[100];
    char topp[100];
    int price;
    int quan;
} order[100];

int index = 0; int money = 0;

void swap(int a, int b) {
    struct order temp = order[a];
    order[a] = order[b];
    order[b] = temp;
}

void quickSortPrice(int low, int high)
{
    if (low < high) {
        int i = low - 1;
        int j = low;
        int pivot = order[high].price;

        while (j < high) {
            if (order[j].price <= pivot) {
                i++;
                swap(i, j);
            }
            j++;
        }
        swap(high, i+1);

        int pos = i+1;

        quickSortPrice(low, pos - 1);
        quickSortPrice(pos, high);
    }
}

void quickSortQuantity(int low, int high)
{
    if (low < high) {
        int i = low - 1;
        int j = low;
        int pivot = order[high].quan;

        while (j < high) {
            if (order[j].quan <= pivot) {
                i++;
                swap(i, j);
            }
            j++;
        }
        swap(high, i+1);

        int pos = i+1;

        quickSortQuantity(low, pos - 1);
        quickSortQuantity(pos, high);
    }
}

void quickSortName(int low, int high)
{
    if (low < high) {
        int i = low - 1;
        int j = low;
        char pivot[200];
        strcpy(pivot, order[high].name);

        while (j < high) {
            if (strcmp(order[j].name, pivot) < 0) {
                i++;
                swap(i, j);
            }
            j++;
        }
        swap(high, i+1);

        int pos = i+1;

        quickSortName(low, pos - 1);
        quickSortName(pos, high);
    }
}

void importData()
{
    FILE* file = fopen("data.txt", "r");

    if (file == NULL) return;
    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%[^#]#%d#%d\n", order[index].name, order[index].rice, order[index].topp, &order[index].price, &order[index].quan);
        index++;
    }

    fclose(file);
}

void addMenu()
{
    int pick1, pick2;
    do {
        printf("Input name: ");
        scanf("%[^\n]", order[index].name); getchar();
    } while (strlen(order[index].name) < 3 || strlen(order[index].name) > 50);

    do {
        printf("Choose Fried Rice:\n");
        puts("1. Vegetarian");
        puts("2. Pork");
        puts("3. Beef");
        puts("4. Chicken");
        printf("Choose fried rice [1 - 4] : "); scanf("%d", &pick1); getchar();
    } while (pick1 < 1 || pick1 > 4);
    if (pick1 == 1) {
        strcpy(order[index].rice, "Vegetarian Fried Rice");
    } else if (pick1 == 2) {
        strcpy(order[index].rice, "Pork Fried Rice");
    } else if (pick1 == 3) {
        strcpy(order[index].rice, "Beef Fried Rice");
    } else {
        strcpy(order[index].rice, "Chicken Fried Rice");
    }

    do {
        printf("Choose Topping:\n");
        puts("1. Omelette");
        puts("2. Mozarella");
        puts("3. Cheddar");
        printf("Choose fried rice [1 - 3] : "); scanf("%d", &pick2); getchar();
    } while (pick2 < 1 || pick2 > 3);
    
    if (pick2 == 1) {
        strcpy(order[index].topp, "Omelette");
    } else if (pick2 == 2) {
        strcpy(order[index].topp, "Mozarella");
    } else {
        strcpy(order[index].topp, "Cheddar");
    }

    do {
        printf("Insert quantity: ");
        scanf("%d", &order[index].quan); getchar();
    } while (order[index].quan < 1 || order[index].quan > 10);

    order[index].price = (rand() % strlen(order[index].name) + 1) * 7000;
    index++;
    printf("Successfully Ordered..."); getchar();
}

void viewAll()
{
    int pick;
    for (int i = 0; i < index; i++) {
        printf("%d. %s with %s\n", i+1, order[i].rice, order[i].topp);
        printf("Ordered by - %s with quantity of %d, price of %d with total of %d\n\n", order[i].name, order[i].quan, order[i].price, order[i].price * order[i].quan);
    }

    puts("");
    puts("1. Order by price");
    puts("2. Order by quantity");
    puts("3. Order by name");
    puts("4. Exit");
    printf("Choose >> "); scanf("%d", &pick); getchar();

    if (pick == 1) {
        quickSortPrice(0, index - 1);
    } else if (pick == 2) {
        quickSortQuantity(0, index - 1);
    } else if (pick == 3) {
        quickSortName(0, index - 1); 
    } else {
        return;
    }
    printf("Successfully sorted!"); getchar();
}

void deleteMenu()
{
    if (index == 0) {
        puts("There are no data!");
        printf("Press enter to continue....."); getchar();
    } else {
        int pick;
        for (int i = 0; i < index; i++) {
            printf("%d. %s with %s\n", i+1, order[i].rice, order[i].topp);
            printf("Ordered by - %s with quantity of %d, price of %d with total of %d\n\n", order[i].name, order[i].quan, order[i].price, order[i].price * order[i].quan);
        }
        printf("Choose ID to delete [1...%d] : ", index); scanf("%d", &pick); getchar();

        money += order[pick - 1].price * order[pick - 1].quan;

        for (int i = pick - 1; i < index - 1; i++) {
			strcpy(order[i].name, order[i+1].name);
			strcpy(order[i].rice, order[i+1].rice);
			strcpy(order[i].topp, order[i+1].topp);
		}
		for (int j = pick - 1; j < index; j++) {
            order[j].price = order[j + 1].price;
            order[j].quan = order[j + 1].quan;
		}
        index--;

        puts("Successfully Deleted!");
        printf("Press enter to continue....."); getchar();
    }
}

void exportData()
{
    FILE* file = fopen("data.txt", "w");

    for (int i = 0; i < index; i++) {
        fprintf(file, "%s#%s#%s#%d#%d\n", order[i].name, order[i].rice, order[i].topp, order[i].price, order[i].quan);
    }

    fclose(file);

    puts("Thanks for ordering!");
}

int main()
{
    int input;
    srand(time(0));
    importData();
    do {
        puts("Random Fried Rice Shop");
        printf("Current Money: $%d\n", money);
        puts("1. Insert Order");
        puts("2. View Order");
        puts("3. Delete Order");
        puts("4. Exit");
        printf("Choose >> "); scanf("%d", &input); getchar();

        if (input == 1) {
            addMenu();
        } else if (input == 2) {
            viewAll();
        } else if (input == 3) {
            deleteMenu();
        } else if (input == 4) {
            exportData();
        } else {
            puts("Invalid Input.....");
            printf("Press any key to continue...."); getchar();
        }
    } while (input != 4);
}