#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct node {
    char name[35];
    char id[20];
    double assets;
    double liabilities;
    double equity;
    struct node* left;
    struct node* right;
} node;

node* root;

node* createNode(char* name, char* id, double l, double e) {
    node* temp = (node*)malloc(sizeof(node));
    temp->equity = e;
    temp->liabilities = l;
    strcpy(temp->name, name);
    strcpy(temp->id, id);
    temp->assets = e + l;
    temp->left = temp->right = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->assets < curr->assets) curr->left = insertNode(curr->left, neww);
    else curr->right = insertNode(curr->right, neww);
    return curr;
}

node* search(node* curr, char* name) {
    if (!curr || strcmp(curr->name, name) == 0) return curr;

    search(curr->left, name);
    search(curr->right, name);
}

node* searchId(node* curr, char* id) {
    if (!curr || strcmp(curr->id, id) == 0) return curr;

    searchId(curr->left, id);
    searchId(curr->right, id);
}

node* deleteNode(node* curr, double assets) {
    if (!curr) return curr;
    else if (assets < curr->assets) curr->left = deleteNode(curr->left, assets);
    else if (assets > curr->assets) curr->right = deleteNode(curr->right, assets);
    else {
        if (!curr->right && !curr->left) {
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
            curr->assets = temp->assets;
            curr->liabilities = temp->liabilities;
            curr->equity = temp->equity;
            strcpy(curr->id, temp->id);
            strcpy(curr->name, temp->name);
            curr->left = deleteNode(curr->left, temp->assets);
        }
    }
    return curr;
}

node* deleteNode2(node* curr, char* id) {
    if (!curr) return curr;
    if (strcmp(curr->id, id) == 0) {
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
            curr->assets = temp->assets;
            curr->liabilities = temp->liabilities;
            curr->equity = temp->equity;
            strcpy(curr->id, temp->id);
            strcpy(curr->name, temp->name);
            curr->left = deleteNode(curr->left, temp->assets);
        }
    }
    else if (!curr->right) curr->left = deleteNode2(curr->left, id);
    else if (!curr->left) curr->right = deleteNode2(curr->right, id);
    return curr;
}

void viewMenu(node* curr) {
    if (curr) {
        viewMenu(curr->left);
        printf("%s\t%s\t%.2lf\t%.2lf\t%.2lf\n", curr->name, curr->id, curr->assets, curr->liabilities, curr->equity);
        viewMenu(curr->right);
    }
}

void addMenu() {
    char name[35];
    char id[20];
    double liabilities;
    double equity;

    do {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 3 || strlen(name) > 30);

    do {
        printf("Enter liabilities [>= 10000]: ");
        scanf("%lf", &liabilities); getchar();
    } while (liabilities < 10000);

    do {
        printf("Enter equity [>= 10000]: ");
        scanf("%lf", &equity); getchar();
    } while (equity < 10000);

    sprintf(id, "ST-%05d-%c%c", rand() % 99999, toupper(name[0]), toupper(name[strlen(name) - 1]));

    root = insertNode(root, createNode(name, id, liabilities, equity));

    printf("Successfully Inserted!\n");
}

void editMenu() {
    char name[35];
    char id[20];
    double assets;
    double liabilities;
    double equity;
    int pick = 0;

    puts("1. Search By ID");
    puts("2. Search By Name");
    do {
        printf(">> "); scanf("%d", &pick); getchar();
    } while (pick != 1 && pick != 2);

    if (pick == 1) {
        printf("Enter Id: ");
        scanf("%s", id); getchar();

        node* target = searchId(root, id);

        if (!target) {
            printf("Student with ID [%s] doesn't exist!\n", id);
        }
        else {
            printf("Student Name: %s\n", target->name);
            printf("Student Id: %s\n", target->id);
            printf("Student Assets: %.2lf\n", target->assets);
            printf("Student Liabilities: %.2lf\n", target->liabilities);
            printf("Student Equity: %.2lf\n", target->equity);

            do {
                printf("Enter liabilities [>= 10000]: ");
                scanf("%lf", &liabilities); getchar();
            } while (liabilities < 10000);

            do {
                printf("Enter equity [>= 10000]: ");
                scanf("%lf", &equity); getchar();
            } while (equity < 10000);

            char yn;
            do {
                printf("Are you sure you want to edit [y|n] ?: ");
                scanf("%c", &yn); getchar();
            } while (yn != 'y' && yn != 'n');

            if (yn == 'y') {
                root = deleteNode(root, target->assets);
                node* neww = createNode(target->name, target->id, liabilities, equity);
                root = insertNode(root, neww);

                printf("Sucessfully Edited!\n");
            }
            else {
                printf("Sucessfully Canceled!\n");
            }
        }
    }
    else {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();

        node* target = search(root, name);

        if (!target) {
            printf("Student %s doesn't exist!\n", name);
        }
        else {
            printf("Student Name: %s\n", target->name);
            printf("Student Id: %s\n", target->id);
            printf("Student Assets: %.2lf\n", target->assets);
            printf("Student Liabilities: %.2lf\n", target->liabilities);
            printf("Student Equity: %.2lf\n", target->equity);

            do {
                printf("Enter liabilities [>= 10000]: ");
                scanf("%lf", &liabilities); getchar();
            } while (liabilities < 10000);

            do {
                printf("Enter equity [>= 10000]: ");
                scanf("%lf", &equity); getchar();
            } while (equity < 10000);

            char yn;
            do {
                printf("Are you sure you want to edit [y|n] ?: ");
                scanf("%c", &yn); getchar();
            } while (yn != 'y' && yn != 'n');

            if (yn == 'y') {
                root = deleteNode(root, target->assets);
                node* neww = createNode(target->name, target->id, liabilities, equity);
                root = insertNode(root, neww);

                printf("Sucessfully Edited!\n");
            }
            else {
                printf("Sucessfully Canceled!\n");
            }
        }
    }
}

void delMenu() {
    char name[35];
    char id[20];
    double assets;
    double liabilities;
    double equity;
    int pick = 0;

    puts("1. Search By ID");
    puts("2. Search By Name");
    do {
        printf(">> "); scanf("%d", &pick); getchar();
    } while (pick != 1 && pick != 2);

    if (pick == 1) {
        printf("Enter Id: ");
        scanf("%s", id); getchar();

        node* target = searchId(root, id);

        if (!target) {
            printf("Student with ID [%s] doesn't exist!\n", id);
        }
        else {
            printf("Student Name: %s\n", target->name);
            printf("Student Id: %s\n", target->id);
            printf("Student Assets: %.2lf\n", target->assets);
            printf("Student Liabilities: %.2lf\n", target->liabilities);
            printf("Student Equity: %.2lf\n", target->equity);

            char yn;
            do {
                printf("Are you sure you want to delete [y|n] ?: ");
                scanf("%c", &yn); getchar();
            } while (yn != 'y' && yn != 'n');

            if (yn == 'y') {
                // root = deleteNode(root, target->assets);
                root = deleteNode2(root, target->id);

                printf("Sucessfully Deleted!\n");
            }
            else {
                printf("Sucessfully Canceled!\n");
            }
        }
    }
    else {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();

        node* target = search(root, name);

        if (!target) {
            printf("Student %s doesn't exist!\n", name);
        }
        else {
            printf("Student Name: %s\n", target->name);
            printf("Student Id: %s\n", target->id);
            printf("Student Assets: %.2lf\n", target->assets);
            printf("Student Liabilities: %.2lf\n", target->liabilities);
            printf("Student Equity: %.2lf\n", target->equity);

            char yn;
            do {
                printf("Are you sure you want to delete [y|n] ?: ");
                scanf("%c", &yn); getchar();
            } while (yn != 'y' && yn != 'n');

            if (yn == 'y') {
                // root = deleteNode(root, target->assets);
                root = deleteNode2(root, target->id);

                printf("Sucessfully Deleted!\n");
            }
            else {
                printf("Sucessfully Canceled!\n");
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    int input = 0;
    do {
        puts("Gators Accounting");
        puts("======================");
        puts("1. View Students");
        puts("2. Add Student");
        puts("3. Edit Student");
        puts("4. Delete Student");
        puts("5. Exit");
        printf(">> "); scanf("%d", &input); getchar();

        if (input == 1) {
            viewMenu(root);
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 2) {
            addMenu();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 3) {
            editMenu();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 4) {
            delMenu();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 5) {
            printf("Bye!\n");
        }
        else {
            printf("Please input a valid number!\n");
            printf("Press enter to continue..."); getchar();
        }
    } while (input != 5);
}
