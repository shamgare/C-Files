#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 201;

struct node {
    char name[55];
    char phone[15];
    char address[200];
    char city[105];
    struct node* next;
};

node* table[size];

unsigned long hash(char* str) {
    /*
    Initialize a variable named hash to some prime number.
    Prime numbers are very useful in generating pseudo-
    random numbers. You don't need to know why it's 5381 as
    it gets very theoretical as to why this is the number
    being used (other than it's a prime number).
    */
    unsigned long hash = 5381;
    int c; // Initialize a variable c

    /*
    This is by far the most confusing, but this
    loop simply goes through each char and assigns
    it to c until you encounter a null-terminator
    */
    while (c = *str++)
        /*
        This is the secret-sauce of the hash function
        which simply does some bit manipulation and
        arithmetic to get the hash
        */
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size;
}

node* createNode(char* name, char* phone, char* address, char* city) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    strcpy(temp->address, address);
    strcpy(temp->city, city);
    temp->next = 0;
    return temp;
}

void insertMenu() {
    char name[55];
    do {
        printf("Input name [3-50 chars]: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    char phone[15];
    do {
        printf("Input phone number [08XX-XXXX-XXXX]: ");
        scanf("%s", phone); getchar();
        if (strlen(phone) != 14) {
            printf("Phone Number Must Be 14 Characters Long!\n");
        }
        else if (phone[0] != '0' || phone[1] != '8') {
            printf("Phone Number Must Begin With 0 and 8\n");
        }
        else if (phone[4] != '-' || phone[9] != '-') {
            printf("Invalid Phone Number!\n");
        }
    } while (strlen(phone) != 14 || phone[0] != '0' || phone[1] != '8' || phone[4] != '-' || phone[9] != '-');

    char address[200];
    do {
        printf("Input address [ends with street]: ");
        scanf("%[^\n]", address); getchar();
    } while (strlen(address) < 8 || strcmp("street", strrchr(address, 's') ? strrchr(address, 's') : "no") != 0);

    char city[105];
    do {
        printf("Input city [3-100 chars]: ");
        scanf("%[^\n]", city); getchar();
    } while (strlen(city) < 3 || strlen(city) > 100);

    unsigned long key = hash(name);

    node* newNode = createNode(name, phone, address, city);
    node* curr = table[key];

    if (!table[key]) {
        table[key] = createNode(name, phone, address, city);
    }
    else if (strcmp(newNode->name, curr->name) < 0) {
        newNode->next = curr;
        table[key] = newNode;
    }
    else {
        while (curr->next && strcmp(newNode->name, curr->next->name) >= 0) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    printf("Press enter to continue..."); getchar();
}

void viewMenu() {
    for (int i = 0; i < size; i++) {
        node* curr = table[i];
        if (curr) {
            printf("%d ->\n", i);
            int j = 1;
            while (curr) {
                printf("\t%d. %s - %s - %s - %s\n", j++, table[i]->name, table[i]->phone, table[i]->address, table[i]->city);
                curr = curr->next;
            }
        }
    }
    printf("Press enter to continue..."); getchar();
}

void updateMenu() {
    char name[55];
    do {
        printf("Input name [3-50 chars]: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    unsigned long key = hash(name);

    if (!table[key]) {
        printf("Not Found!\n");
        printf("Press enter to continue..."); getchar();
        return;
    }
    else {
        node* temp = table[key];
        node* change;
        if (strcmp(temp->name, name) == 0) {
            change = temp;
        }
        else {
            while (temp->next && strcmp(temp->next->name, name) != 0) {
                temp = temp->next;
            }
            if (!temp->next) {
                printf("Not Found!\n");
                printf("Press enter to continue..."); getchar();
                return;
            }
            change = temp->next;
        }

        char phone[15];
        do {
            printf("Input phone number [08XX-XXXX-XXXX]: ");
            scanf("%s", phone); getchar();
        } while (strlen(phone) != 14 || phone[0] != '0' || phone[1] != '8' || phone[4] != '-' || phone[9] != '-');

        char address[200];
        do {
            printf("Input address [ends with street]: ");
            scanf("%[^\n]", address); getchar();
        } while (strlen(address) < 8 || address[strlen(address) - 1] != 't' || address[strlen(address) - 2] != 'e' ||
            address[strlen(address) - 3] != 'e' || address[strlen(address) - 4] != 'r' ||
            address[strlen(address) - 5] != 't' || address[strlen(address) - 6] != 's');

        char city[105];
        do {
            printf("Input city [3-100 chars]: ");
            scanf("%[^\n]", city); getchar();
        } while (strlen(city) < 3 || strlen(city) > 100);

        strcpy(change->phone, phone);
        strcpy(change->address, address);
        strcpy(change->city, city);
    }

    printf("Press enter to continue..."); getchar();
}

void removeMenu() {
    char name[55];
    do {
        printf("Input name [3-50 chars]: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    unsigned long key = hash(name);

    if (!table[key]) {
        printf("Not Found!\n");
        printf("Press enter to continue..."); getchar();
        return;
    }
    else {
        node* temp = table[key];
        node* del;
        if (strcmp(temp->name, name) == 0) {
            del = temp;
            free(del); del = 0;
        }
        else {
            while (temp->next && strcmp(temp->next->name, name) != 0) {
                temp = temp->next;
            }
            if (!temp->next) {
                printf("Not Found!\n");
                printf("Press enter to continue..."); getchar();
                return;
            }
            node* a = temp;
            del = temp->next;
            node* b = temp->next->next;

            a->next = b;
            free(del); del = 0;
        }
    }
    printf("Press enter to continue..."); getchar();
}

void searchMenu() {
    char name[55];
    do {
        printf("Input name [3-50 chars]: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    unsigned long key = hash(name);

    if (!table[key]) {
        printf("Not Found!\n");
        printf("Press enter to continue..."); getchar();
        return;
    }
    else {
        node* temp = table[key];
        node* find;
        if (strcmp(temp->name, name) == 0) {
            find = temp;
        }
        else {
            while (temp->next && strcmp(temp->next->name, name) != 0) {
                temp = temp->next;
            }
            if (!temp->next) {
                printf("Not Found!\n");
                printf("Press enter to continue..."); getchar();
                return;
            }
            find = temp->next;
        }
        printf("Data Found!\n");
        printf("%s - %s - %s - %s\n", find->city, find->phone, find->address, find->city);
    }

    printf("Press enter to continue..."); getchar();
}

int main()
{
    int input = 0;
    do {
        // system("cls");
        puts("My Hashed Phone Book");
        puts("1. Insert New Phone Number");
        puts("2. View All Phone Book");
        puts("3. Update Phone Info By Name");
        puts("4. Remove Phone Info By Name");
        puts("5. Search Phone By Name");
        puts("6. Exit");
        printf("Choose [ 1 - 6 ]: "); scanf("%d", &input); fflush(stdin);

        switch (input)
        {
        case 1:
            system("cls");
            insertMenu();
            break;
        case 2:
            system("cls");
            viewMenu();
            break;
        case 3:
            system("cls");
            updateMenu();
            break;
        case 4:
            system("cls");
            removeMenu();
            break;
        case 5:
            system("cls");
            searchMenu();
            break;
        case 6:
            printf("Bye Bye\n");
            break;
        default:
            puts("Please input a valid number!");
            printf("Press enter to continue..."); getchar();
            break;
        }
    } while (input != 6);
}