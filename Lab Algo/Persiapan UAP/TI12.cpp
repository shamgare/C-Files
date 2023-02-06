#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct order {
    char code[200];
    char name[200];
    char type[100];
    int price;
    int quan;
} order[100];

struct order purchase[100];

int index = 0;
int flag = 0;

void swap(int a, int b)
{
    struct order temp = order[a];
    order[a] = order[b];
    order[b] = temp;
}

int partition(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[200];
    strcpy(pivot, order[high].name);

    while (j < high) {
        if (strcmp(order[j].name, pivot) > 0) {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i+1, high);

    return i+1;
}

void quickSort(int low, int high)
{
    if (low < high) {
        int pos = partition(low, high);

        quickSort(low, pos - 1);
        quickSort(pos, high);
    }
}

void random()
{
    srand(time(0));
    char temp1 = order[index].name[0];
    char temp2 = order[index].name[1];
    if (order[index].name[0] >= 97 && order[index].name[0] <= 122) temp1 -= 32;
    if (order[index].name[1] >= 97 && order[index].name[1] <= 122) temp2 -= 32;

    sprintf(order[index].code, "%c%c-%d%d%d-%c%c", temp1, temp2, rand() % 10, rand() % 10, rand() % 10, rand() % 26 + 65, rand() % 26 + 65);
}

void importData()
{
    FILE* file = fopen("ShoPAI.txt", "r");

    if (file == NULL) return;

    int type;
    while (!feof(file)) {
        fscanf(file, "%[^/]/%[^/]/%d/%d/%d\n", 
        order[index].code, order[index].name, &type,
        &order[index].price, &order[index].quan);

        if (type == 1) {
            strcpy(order[index].type, "Housing Appliances");
        } else if (type == 2) {
            strcpy(order[index].type, "Utility");
        } else if (type == 3) {
            strcpy(order[index].type, "Toys");
        }

        if (strcmp(order[index].code, "") != 0) index++;
    }

    fclose(file);
}

void addMenu()
{
    int type;
    puts("1. Household Appliances");
    puts("2. Utility");
    puts("3. Toys");

    do {
        printf("Which Item do you want to add? [1-3] : ");
        scanf("%d", &type); getchar();
    } while (type < 1 || type > 3);
    if (type == 1) {
        strcpy(order[index].type, "Housing Appliances");
    } else if (type == 2) {
        strcpy(order[index].type, "Utility");
    } else {
        strcpy(order[index].type, "Toys");
    }

    do {
        printf("Input Item name [5 - 20 characters] : ");
        scanf("%[^\n]", order[index].name); getchar();
    } while (strlen(order[index].name) < 5 || strlen(order[index].name) > 20);
    do {
        printf("Input Item price [15.000 - 300.000] : ");
        scanf("%d", &order[index].price); getchar();
    } while (order[index].price < 15000 || order[index].price > 300000);
    do {
        printf("Input Item quantity [must be more than 0] : ");
        scanf("%d", &order[index].quan); getchar();
    } while (order[index].quan <= 0);

    random();

    puts("Data added successfully!"); printf("Press enter to continue...."); getchar();
    index++;
}

void display()
{
    puts("==================================================================================================================");
    puts("| [No. ] |   Item Code   |         Item Name          |       Item Type       |    Item Price    | Item Quantity |");
    puts("==================================================================================================================");
    if (index == 0) {
        puts("No data yet...."); 
        return;
    } else {
        for (int i = 0; i < index; i++) {
            printf("| [%3d.] | %13s | %26s | %21s | %16d | %13d |\n", i+1, order[i].code, order[i].name, order[i].type, order[i].price, order[i].quan);   
        }
        puts("==================================================================================================================");
    }
}

void viewAll()
{
    puts("1. Housing Appliances");
    puts("2. Utility");
    puts("3. Toys");
    puts("4. All");
    puts("5. Back");

    int pick;
    do {
        printf("Which menu do you want to see? [1-5] : ");
        scanf("%d", &pick); getchar();
    } while (pick < 1 || pick > 5);

    quickSort(0, index-1);

    int dex = 0;
    if (pick == 1) {
        puts("==================================================================================================================");
        puts("| [No. ] |   Item Code   |         Item Name          |       Item Type       |    Item Price    | Item Quantity |");
        puts("==================================================================================================================");
        if (index == 0) {
            puts("No data yet...."); 
            return;
        } else {
            for (int i = 0; i < index; i++) {
                if (strcmp(order[i].type, "Housing Appliances") == 0) printf("| [%3d.] | %13s | %26s | %21s | %16d | %13d |\n", dex+=1, order[i].code, order[i].name, order[i].type, order[i].price, order[i].quan);  
            }
            puts("==================================================================================================================");
        }
    } else if (pick == 2) {
        puts("==================================================================================================================");
        puts("| [No. ] |   Item Code   |         Item Name          |       Item Type       |    Item Price    | Item Quantity |");
        puts("==================================================================================================================");
        if (index == 0) {
            puts("No data yet...."); 
            return;
        } else {
            for (int i = 0; i < index; i++) {
                if (strcmp(order[i].type, "Utility") == 0) printf("| [%3d.] | %13s | %26s | %21s | %16d | %13d |\n", dex+=1, order[i].code, order[i].name, order[i].type, order[i].price, order[i].quan);  
            }
            puts("==================================================================================================================");
        }
    } else if (pick == 3) {
        puts("==================================================================================================================");
        puts("| [No. ] |   Item Code   |         Item Name          |       Item Type       |    Item Price    | Item Quantity |");
        puts("==================================================================================================================");
        if (index == 0) {
            puts("No data yet...."); 
            return;
        } else {
            for (int i = 0; i < index; i++) {
                if (strcmp(order[i].type, "Toys") == 0) printf("| [%3d.] | %13s | %26s | %21s | %16d | %13d |\n", dex+=1, order[i].code, order[i].name, order[i].type, order[i].price, order[i].quan);  
            }
            puts("==================================================================================================================");
        }
    } else if (pick == 4) {
        display();
    } else if (pick == 5) {
        return;
    }
}

void purchaseMenu()
{
    char yesno[5]; flag = 0;
    do {
        
        display();

        int pick;
        do {
            printf("Input item number to buy [1-%d] : ", index); 
            scanf("%d", &pick); getchar();
        } while (pick <= 0 || pick > index);

        int quan;
        if (order[pick-1].quan == 0) {
            printf("This item is sold out..."); getchar(); return;
        } else {  
            do {
                printf("Input item quantity to buy: ");
                scanf("%d", &quan); getchar();
            } while (quan <= 0 || quan > order[pick-1].quan);

            order[pick-1].quan -= quan;

            purchase[flag] = order[pick-1];
            purchase[flag].quan = quan;
            flag++;
                
            if (index >= 2) {
                do {
                    memset(yesno, 0, sizeof(yesno));
                    printf("Do you want to purchase another item [ Yes | No ] (case sensitive)? : ");
                    scanf("%s", &yesno); getchar(); 
                } while (strcmp(yesno, "Yes") != 0 && strcmp(yesno, "No") != 0);
            }
        }
    } while (strcmp(yesno, "Yes") == 0);

    puts("+---------------------+");
    puts("| ShoPAI Bill Payment |");
    puts("+---------------------+");
    
    int totQuan = 0, totPrice = 0;
    for (int i = 0; i < flag; i++) {
        printf("[%s] ==> %s\n\n", purchase[i].code, purchase[i].name);
        printf("%d x %d IDR = %d\n", purchase[i].quan, purchase[i].price, purchase[i].quan * purchase[i].price);
        totPrice += purchase[i].price * purchase[i].quan;
        totQuan += purchase[i].quan;
    }

    puts("-----------------------------------------");
    printf("Total Item : %d Item(s)\n", totQuan);
    puts("-----------------------------------------");
    printf("Total Price : IDR %d\n", totPrice);
    printf("Tax : IDR %d\n", totPrice/10 );
    printf("Grand Total Price : IDR %d\n", totPrice + (totPrice/10));
    puts("-----------------------------------------");
    printf("Thank you for your purchase at ShoPAI\n");
    printf("Press enter to continue......"); getchar();
}

void exportData()
{
    puts("Thanks for ordering!");

    FILE* file = fopen("ShoPAI.txt", "r");

    for (int i = 0; i < index; i++) {
        if (strcmp(order[i].type, "Housing Appliances") == 0) {
            strcpy(order[i].type, "1");
        } else if (strcmp(order[i].type, "Utility") == 0) {
            strcpy(order[i].type, "2");
        } else {
            strcpy(order[i].type, "3");
        }

        fprintf(file, "%s/%s/%d/%d/%d\n", order[i].code, order[i].name, order[i].type, order[i].price, order[i].quan);
    }

    fclose(file);
}

int main()
{
    int input;
    importData();

    do {
        puts("Welcome to ShoPAI");
        puts("===================");
        puts("1. Add New Item");
        puts("2. View Item(s)");
        puts("3. Purchase Item(s)");
        puts("4. Exit");
        printf(">> "); scanf("%d", &input); getchar();

        if (input == 1) {
            addMenu();
        } else if (input == 2) {
            viewAll();
            printf("Press enter to continue......"); getchar();
        } else if (input == 3) {
            purchaseMenu();
        } else if (input == 4) {
            exportData();
        } else {
            puts("Please input a valid number..."); getchar();
        }
    } while (input != 4);

}