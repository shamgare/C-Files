#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int id;
    int type;
    char name[100];
    char mem[20];
    node* next;
};

node* head = 0;

node* createNode(int id, char* name, char* mem, int type) {
    node* temp = (node*)malloc(sizeof(node));
    temp->id = id;
    temp->type = type;
    strcpy(temp->mem, mem);
    strcpy(temp->name, name);
    temp->next = 0;
    return temp;
}

void insertNode(node* neww) {
    node* curr = head;

    if (!head) {
        head = neww;
    }
    else if (neww->type > head->type) {
        neww->next = curr;
        head = neww;
    }
    else {
        while (curr->next && neww->type < curr->next->type) {
            curr = curr->next;
        }
        neww->next = curr->next;
        curr->next = neww;
    }
}

node* searchNode(char* name) {
    node* curr = head;
    if (strcmp(curr->name, name) == 0) return curr;

    while (curr->next && strcmp(curr->next->name, name) != 0) {
        curr = curr->next;
    }
    if (!curr->next) {
        return 0;
    }
    return curr->next;
}

void importData() {
    int id, type;
    char name[100];
    char mem[20];
    FILE* file = fopen("customers.txt", "r");
    while (!feof(file)) {
        fscanf(file, "%d#%[^#]#%d\n", &id, name, &type);

        if (type == 1) {
            strcpy(mem, "Non-Member");
        }
        else if (type == 2) {
            strcpy(mem, "Bronze");
        }
        else if (type == 3) {
            strcpy(mem, "Silver");
        }
        else if (type == 4) {
            strcpy(mem, "Gold");
        }
        else {
            strcpy(mem, "Platinum");
        }
        node* neww = createNode(id, name, mem, type);
        insertNode(neww);
    }
}

void addMenu() {
    char name[100];
    printf("Enter name: ");
    scanf("%[^\n]", name); getchar();

    node* find = searchNode(name);
    if (!find) {
        printf("Membership data not found!\n");
    }
    else {
        printf("Membership data found!\n");
        printf("Customer ID     : %d\n", find->id);
        printf("Customer Name   : %s\n", find->name);
        printf("Membership Type : %s\n", find->mem);
    }
    printf("Press enter to continue..."); getchar();
}

void viewMenu() {
    node* curr = head;
    while (curr) {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

void serveMenu() {

}

int main()
{
    importData();
    int input = 0;
    do {
        puts("Hov's Fresh Concoction");
        puts("============================");
        puts("1. Add New Order");
        puts("2. View Order");
        puts("3. Serve Order");
        puts("4. Exit");
        printf("Choose: "); scanf("%d", &input); getchar();

        switch (input)
        {
        case 1:
            addMenu();
            break;
        case 2:
            viewMenu();
            break;
        case 3:
            serveMenu();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (input != 4);
}