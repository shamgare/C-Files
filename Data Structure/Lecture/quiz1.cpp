#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char name[55];
    char nim[20];
    struct node* left;
    struct node* right;
} node;

node* root;

node* createNode(char* name, char* nim) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->nim, nim);
    temp->left = temp->right = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (strcmpi(neww->name, curr->name) < 0) {
        curr->left = insertNode(curr->left, neww);
    }
    else {
        curr->right = insertNode(curr->right, neww);
    }
    return curr;
}

node* search(node* curr, char* name) {
    if (!curr || strcmp(name, curr->name) == 0) return curr;
    else if (strcmp(name, curr->name) < 0) {
        return search(curr->left, name);
    }
    else {
        return search(curr->right, name);
    }
}

node* deleteNode(node* curr, char* name) {
    if (!curr) return 0;
    else if (strcmp(name, curr->name) < 0) curr->left = deleteNode(curr->left, name);
    else if (strcmp(name, curr->name) > 0) curr->right = deleteNode(curr->right, name);
    else {
        if (!curr->left && !curr->right) {
            free(curr); curr = 0;
        }
        else if (!curr->left) {
            node* temp = curr;
            curr = curr->right;
            free(temp); temp = 0;
        }
        else if (!curr->right) {
            node* temp = curr;
            curr = curr->left;
            free(temp); temp = 0;
        }
        else {
            node* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            strcpy(curr->nim, temp->nim);
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

bool isNumeric(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}

void insertMenu() {
    char name[55];
    char nim[20];
    do {
        printf("Input name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    do {
        printf("Input nim: ");
        scanf("%s", nim); getchar();
    } while (strlen(nim) != 8 || !isNumeric(nim));

    node* find = search(root, name);

    if (find) {
        printf("Student name already exists! Updated NIM instead.\n");
        strcpy(find->nim, nim);
    }
    else {
        printf("Successfully Inserted Student!\n");
        root = insertNode(root, createNode(name, nim));
    }
    printf("Press enter to continue..."); getchar();
}

void delMenu() {
    char name[55];
    do {
        printf("Input name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);

    node* find = search(root, name);

    if (find) {
        root = deleteNode(root, find->name);
        printf("Successfully Deleted Student!\n");
    }
    else {
        printf("Cannot delete because student name does not exist!\n");
    }
    printf("Press enter to continue..."); getchar();
}

void view(node* curr) {
    if (curr) {
        view(curr->left);
        printf("%s %s\n", curr->name, curr->nim);
        view(curr->right);
    }
}

int main() {
    int input = 0;
    do {
        puts("=========================");
        puts("| BST Class             |");
        puts("=========================");
        puts("| 1. Insert Student [1] |");
        puts("| 2. Delete Student [2] |");
        puts("| 3. Exit           [3] |");
        puts("=========================");
        printf("Choose >> "); scanf("%d", &input); getchar();

        if (input == 1) {
            insertMenu();
        }
        else if (input == 2) {
            delMenu();
        }
        else if (input == 3) {
            printf("Bye Bye!");
        }
        else {
            printf("Please input a valid number!");
            printf("Press enter to continue..."); getchar();
        }
    } while (input != 3);
}