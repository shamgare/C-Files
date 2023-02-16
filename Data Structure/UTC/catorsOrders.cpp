#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 1000

struct membership {
    char name[20];
    membership* left, * right;
} *rootMem;

membership* createMem(const char* name) {
    membership* temp = (membership*)malloc(sizeof(membership));
    strcpy(temp->name, name);
    temp->left = temp->right = 0;
    return temp;
}

membership* insertMem(membership* curr, membership* neww) {
    if (!curr) return neww;
    else if (strcmp(neww->name, curr->name) < 0) {
        curr->left = insertMem(curr->left, neww);
    }
    else {
        curr->right = insertMem(curr->right, neww);
    }
    return curr;
}

membership* search(membership* curr, char* name) {
    if (!curr || strcmp(name, curr->name) == 0) return curr;
    else if (strcmp(name, curr->name) < 0) {
        return search(curr->left, name);
    }
    else {
        return search(curr->right, name);
    }
}

struct node {
    char name[100];
    char mem[15];
    node* next;
} *table[size];

node* createNode(char* name, char* mem) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->mem, mem);
    temp->next = 0;
    return temp;
}

int hash(char* name) {
    char first;
    char last;
    if (name[0] >= 'a' && name[0] <= 'z') {
        first = name[0] - 'a';
    }
    else if (name[0] >= 'A' && name[0] <= 'Z') {
        first = name[0] - 'A';
    }
    else {
        first = name[0];
    }
    if (name[strlen(name) - 1] >= 'a' && name[strlen(name) - 1] <= 'z') {
        last = name[strlen(name) - 1] - 'a';
    }
    else if (name[strlen(name) - 1] >= 'A' && name[strlen(name) - 1] <= 'Z') {
        last = name[strlen(name) - 1] - 'A';
    }
    else {
        last = name[strlen(name) - 1];
    }
    return (first * last) % size;
}

void searchCust(char* name) {
    int key = hash(name);
    node* curr = table[key];

    if (!curr) {
        printf("%s not found!");
    }
    else if (strcmp(curr->name, name) == 0) {
        printf("");
    }
}

void checkMenu() {
    char name[100];
    do {
        printf("Input name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3);

}

void createMenu() {
    char name[100];
    do {
        printf("Input name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3);

    char mem[15];
    do {
        printf("Input membership: ");
        scanf("%[^\n]", mem); getchar();
    } while (!search(rootMem, mem));

    int key = hash(name);
    node* curr = table[key];
    node* neww = createNode(name, mem);

    if (!curr) {
        table[key] = neww;
    }
    else if (strcmp(neww->mem, curr->mem) < 0) {
        neww->next = curr;
        table[key] = neww;
    }
    else {
        while (curr->next && strcmp(neww->mem, curr->next->mem) >= 0) {
            // if (strcmp(neww->mem, curr->next->mem) == 0) {
            //     if (strcmp(neww->name, curr->name) < 0) {
            //         break;
            //     }
            //     else curr = curr->next;
            // }
            curr = curr->next;
        }
        neww->next = curr->next;
        curr->next = neww;
    }

    printf("Your order has been added to the queue.\n");
    printf("Press enter to continue..."); getchar();

}

void viewMenu() {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (table[i]) {
            node* curr = table[i];
            while (curr) {
                // printf("Name        : %s\n", curr->name);
                // printf("Membership  : %s\n", curr->mem);
                j++;
                curr = curr->next;
            }
        }
    }
    if (j != 0) {
        printf("There are %d orders in the queue\n", j);
        for (int i = 0; i < size; i++) {
            if (table[i]) {
                node* curr = table[i];
                while (curr) {
                    printf("Name        : %s\n", curr->name);
                    printf("Membership  : %s\n", curr->mem);
                    curr = curr->next;
                }
            }
        }
    }
    else {
        printf("No Data Yet!\n");
    }
}

void serveMenu() {

}

int main()
{
    rootMem = insertMem(rootMem, createMem("Package A"));
    rootMem = insertMem(rootMem, createMem("Package B"));
    rootMem = insertMem(rootMem, createMem("Package C"));
    rootMem = insertMem(rootMem, createMem("Package D"));
    rootMem = insertMem(rootMem, createMem("Package E"));

    int input = 0;
    do {
        puts("============================================");
        puts("| Cators Orders                            |");
        puts("============================================");
        puts("| 1. Check Order Status                    |");
        puts("| 2. Create New Order                      |");
        puts("| 3. View Order Queue                      |");
        puts("| 4. Serve An Order                        |");
        puts("| 5. Close The Program                     |");
        puts("============================================");
        printf("Choose : "); scanf("%d", &input); getchar();

        if (input == 1) {
            checkMenu();
        }
        else if (input == 2) {
            createMenu();
        }
        else if (input == 3) {
            viewMenu();
        }
        else if (input == 4) {
            serveMenu();
        }
        else if (input == 5) {
            printf("Bye Bye");
        }
        else {
            puts("Invalid Choice!");
            printf("Press enter to continue..."); getchar();
        }
    } while (input != 5);
}