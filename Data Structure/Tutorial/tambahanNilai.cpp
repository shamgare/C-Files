#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char name[105];
    int rating;
    int hours;
    struct node* left;
    struct node* right;
    struct node* next;
    struct node* prev;
} node;

node* root = 0;
node* head = 0;

node* createNode(char* name, int rating, int hours) {
    node* temp = (node*)malloc(sizeof(node));
    temp->rating = rating;
    temp->hours = hours;
    strcpy(temp->name, name);
    temp->left = temp->right = temp->next = temp->prev = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (strcmpi(neww->name, curr->name) > 0) curr->left = insertNode(curr->left, neww);
    else if (strcmpi(neww->name, curr->name) < 0) curr->right = insertNode(curr->right, neww);
    return curr;
}

node* deleteNode(node* curr, char* name) {
    if (!curr) return curr;
    else if (strcmpi(name, curr->name) > 0) curr->left = deleteNode(curr->left, name);
    else if (strcmpi(name, curr->name) < 0) curr->right = deleteNode(curr->right, name);
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
            while (temp->right) temp = temp->right;
            strcpy(curr->name, temp->name);
            curr->hours = temp->hours;
            curr->rating = temp->rating;
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

node* searchNode(node* curr, char* name) {
    if (!curr || strcmp(curr->name, name) == 0) return curr;
    else if (strcmpi(name, curr->name) < 0) return searchNode(curr->right, name);
    else if (strcmpi(name, curr->name) > 0) return searchNode(curr->left, name);
}

void insertQueue(node* neww) {
    node* curr = head;
    if (!head) {
        head = neww;
    }
    else if (neww->rating > head->rating) {
        neww->next = curr;
        curr->prev = neww;
        head = neww;
    }
    else {
        while (curr->next && neww->rating <= curr->next->rating) curr = curr->next;
        if (!curr->next) {
            neww->next = curr->next;
            neww->prev = curr;
            curr->next = neww;
        }
        else {
            neww->next = curr->next;
            neww->prev = curr;
            curr->next->prev = neww;
            curr->next = neww;
        }
    }
}

void deleteQueue(char* name) {
    node* curr = head;

    if (strcmp(curr->name, name) == 0) {
        head = curr->next;
    }
    else {
        while (curr->next && strcmp(name, curr->next->name) != 0) {
            curr = curr->next;
        }

        if (!curr->next) return;

        node* del = curr->next;

        if (!del->next) {
            curr->next = 0;
        }
        else {
            curr->next = del->next;
            del->next->prev = curr;
        }
    }
}

int isAlphanum(char* name) {
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] == ' ') && !(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= '0' && name[i] <= '9')) {
            return -1;
        }
    }
    return 1;
}

int isNumeric(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return -1;
    }
    return 1;
}

int convert(char* str) {
    int result = atoi(str);
    return result;
}

void view(node* curr) {
    if (curr) {
        view(curr->left);
        printf("| %-32s | %-7d | %-12d |\n", curr->name, curr->rating, curr->hours);
        view(curr->right);
    }
}

void insertMenu() {
    char name[105] = {};
    char strHours[5] = {};
    char strRating[5] = {};
    int hours = 0;
    int rating = 0;

    do {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 1 || strlen(name) > 100 || isAlphanum(name) == -1);

    node* find = searchNode(root, name);

    do {
        printf("Enter rating: ");
        scanf("%s", strRating); getchar();
        rating = convert(strRating);
    } while (rating < 1 || rating > 10 || isNumeric(strRating) == -1);

    if (find) {
        find->rating = rating;
    }
    else {
        do {
            printf("Enter played hours: ");
            scanf("%s", strHours); getchar();
            hours = convert(strHours);
        } while (hours < 0 || hours > 2000 || isNumeric(strHours) == -1);

        node* neww = createNode(name, rating, hours);

        root = insertNode(root, neww);
        insertQueue(neww);
    }

    printf("Successfully Inserted!\n");
}

void deleteMenu() {
    char name[105] = {};

    do {
        printf("Enter name: ");
        scanf("%[^\n]", name); getchar();
    } while (strlen(name) < 1 || strlen(name) > 100 || isAlphanum(name) == -1);

    node* find = searchNode(root, name);

    if (!find) {
        printf("Game name does not exist!\n");
    }
    else {
        deleteQueue(name);
        root = deleteNode(root, name);
        printf("Successfully Deleted!\n");
    }
}

void viewRating() {
    node* curr = head;
    while (curr) {
        printf("| %-32s | %-7d | %-12d |\n", curr->name, curr->rating, curr->hours);
        curr = curr->next;
    }
}

int main()
{
    int input = 0;
    do {
        puts("X Games List");

        view(root);

        puts("1. Insert Game");
        puts("2. Delete Game");
        puts("3. View Game by Rating");
        puts("4. Exit");
        printf(">> "); scanf("%d", &input); getchar();

        if (input == 1) {
            insertMenu();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 2) {
            deleteMenu();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 3) {
            viewRating();
            printf("Press enter to continue..."); getchar();
        }
        else if (input == 4) {
            printf("Exit!\n");
        }
        else {
            puts("Please enter a valid number!");
            printf("Press enter to continue..."); getchar();
        }
    } while (input != 4);
}