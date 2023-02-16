#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cust {
    char name[51];
    char membership[20];
    struct cust* left;
    struct cust* right;
} *rootCust;

struct mem {
    char type[20];
    struct mem* left;
    struct mem* right;
} *rootMem;

cust* createCust(char* name, char* membership) {
    cust* temp = (cust*)malloc(sizeof(cust));
    strcpy(temp->name, name);
    strcpy(temp->membership, membership);
    temp->left = temp->right = 0;
    return temp;
}

mem* createMem(const char* type) {
    mem* temp = (mem*)malloc(sizeof(mem));
    strcpy(temp->type, type);
    temp->left = temp->right = 0;
    return temp;
}

mem* insertMem(mem* curr, mem* neww) {
    if (!curr) return neww;
    
    if (strcmp(curr->type, neww->type) < 0) {
        curr->right = insertMem(curr->right, neww);
    }
    else if (strcmp(curr->type, neww->type) > 0) {
        curr->left = insertMem(curr->left, neww);
    }
    
    return curr;
}

cust* insertCust(cust* curr, cust* neww) {
    if (!curr) return neww;
    
    if (strcmp(curr->name, neww->name) < 0) {
        curr->right = insertCust(curr->right, neww);
    }
    else if (strcmp(curr->name, neww->name) > 0) {
        curr->left = insertCust(curr->left, neww);
    }
    
    return curr;
}

cust* deleteCust(cust* curr, char* name) {
    if (!curr) {
        return curr;
    }
    else if (strcmp(curr->name, name) < 0) {
        curr->right = deleteCust(curr->right, name);
    }
    else if (strcmp(curr->name, name) < 0) {
        curr->left = deleteCust(curr->left, name);
    }
    else {
        if (!curr->left && !curr->right) {
            free(curr); curr = 0;
        }
        else if (!curr->left) {
            cust* temp = curr;
            curr = curr->right;
            free(temp); temp = 0;
        }
        else if (!curr->right) {
            cust* temp = curr;
            curr = curr->left;
            free(temp); temp = 0;
        }
        else {
            cust* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            strcpy(curr->membership, temp->membership);
            curr->left = deleteCust(curr->left, temp->name);
        }
    }
    return curr;
}

cust* searchCust(cust* curr, char* name) {
    if (!curr || strcmpi(curr->name, name) == 0) {
        return curr;
    }
    else if (strcmpi(curr->name, name) < 0) {
        return searchCust(curr->right, name);
    }
    else if (strcmpi(curr->name, name) > 0) {
        return searchCust(curr->left, name);
    }
}

mem* searchMem(mem* curr, char* type) {
    if (!curr || strcmp(curr->type, type) == 0) {
        return curr;
    }
    else if (strcmp(curr->type, type) < 0) {
        return searchMem(curr->right, type);
    }
    else if (strcmp(curr->type, type) > 0) {
        return searchMem(curr->left, type);
    }
}

void view(cust* curr) {
    if (curr) {
        view(curr->left);
        printf("%s - %s\n", curr->name, curr->membership);
        view(curr->right);
    }
}

void menu1() {
    char name[101];
    char mem[20];

    do {
        printf("Please enter your name: ");
        scanf("%s", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);
    
    do {
        printf("Please enter your membership: ");
        scanf("%s", mem); getchar();
    } while (searchMem(rootMem, mem) == 0);

    if (searchCust(rootCust, name)) {
        cust* curr = searchCust(rootCust, name);
        strcpy(curr->membership, mem);
        puts("Customer already exists! Updated membership.");
        printf("Press enter to continue..."); getchar();
    }
    else {
        rootCust = insertCust(rootCust, createCust(name, mem));
        puts("Successfully added customer!");
        printf("Press enter to continue..."); getchar();
    }
}

void menu2() {
    puts("====================");
    puts("|  CUSTOMERS LIST  |");
    puts("====================");
    view(rootCust);
    printf("Press enter to continue..."); getchar();
}

void menu3() {
    char name[101];
    do {
        printf("Please enter the customer's name: ");
        scanf("%s", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    if (searchCust(rootCust, name)) {
        cust* curr = searchCust(rootCust, name);
        rootCust = deleteCust(rootCust, curr->name);
        printf("Successfully deleted customer!\n");
        printf("Press enter to continue..."); getchar();
    }
    else {
        printf("Customer not found! Delete cancelled.\n");
        printf("Press enter to continue..."); getchar();
    }
}

int main()
{
    int input = 0;
    do {
        rootMem = insertMem(rootMem, createMem("Non-Member"));
        rootMem = insertMem(rootMem, createMem("Bronze"));
        rootMem = insertMem(rootMem, createMem("Silver"));
        rootMem = insertMem(rootMem, createMem("Gold"));
        rootMem = insertMem(rootMem, createMem("Platinum"));
        
        puts("==================================");
        puts("|     HOV'S FRESH CONCOCTION     |");
        puts("==================================");
        puts("| 1. Add New Customer            |");
        puts("| 2. View Customers              |");
        puts("| 3. Delete Customer             |");
        puts("| 4. Exit                        |");
        puts("==================================");
        printf(">> "); scanf("%d", &input); getchar();

        switch (input) {
        case 1:
            system("cls");
            menu1();
            break;
        case 2:
            system("cls");
            menu2();
            break;
        case 3:
            system("cls");
            menu3();
            break;
        case 4:
            printf("Thanks for using this app!");
            break;
        default:
            printf("Please input a valid number!");
            printf("Press enter to continue..."); getchar();
            break;
        }
    } while (input != 4);
}