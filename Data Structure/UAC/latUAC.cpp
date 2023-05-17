#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char username[100];
    char job[20];
    int score, match, win, lose, draw, wr;
    struct node* left, * right, * next;
    int height;
} node;

node* root = 0;

int getMax(int a, int b) {
    return a >= b ? a : b;
}
int getHeight(node* curr) {
    return !curr ? 0 : 1 + getMax(getHeight(curr->left), getHeight(curr->right));
}
int getBf(node* curr) {
    return !curr ? 0 : getHeight(curr->left) - getHeight(curr->right);
}

node* leftR(node* curr) {
    node* newParent = curr->right;
    node* child = newParent->left;

    curr->right = child;
    newParent->left = curr;

    curr->height = getHeight(curr);
    newParent->height = getHeight(newParent);

    return newParent;
}

node* rightR(node* curr) {
    node* newParent = curr->left;
    node* child = newParent->right;

    curr->left = child;
    newParent->right = curr;

    curr->height = getHeight(curr);
    newParent->height = getHeight(newParent);

    return newParent;
}

node* createNode(const char* username, int job, int score, int match, int win, int lose, int draw) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->username, username);

    if (job == 0) strcpy(temp->job, "Novice");
    else if (job == 1) strcpy(temp->job, "Warrior");
    else if (job == 2) strcpy(temp->job, "Sniper");
    else if (job == 3) strcpy(temp->job, "Wizard");
    else if (job == 4) strcpy(temp->job, "Druid");
    else if (job == 5) strcpy(temp->job, "Assassin");

    temp->score = score;
    temp->match = match;
    temp->win = win;
    temp->lose = lose;
    temp->draw = draw;
    temp->wr = ((double)win / (double)match) * 100;
    temp->height = 1;
    temp->left = temp->right = temp->next = 0;

    return temp;
}




//=================================
node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->score < curr->score) {
        curr->left = insertNode(curr->left, neww);
    }
    else if (neww->score > curr->score) {
        curr->right = insertNode(curr->right, neww);
    }
    else {
        node* temp = curr;
        if (neww->wr > curr->wr) {
            neww->next = temp;
            neww->left = temp->left;
            neww->right = temp->right;
            temp->right = temp->left = 0;
            curr = neww;
        }
        else {
            while (temp->next && neww->wr <= temp->next->wr) {
                temp = temp->next;
            }
            neww->next = temp->next;
            temp->next = neww;
        }
    }

    curr->height = getHeight(curr);
    int bf = getBf(curr);

    if (bf > 1) {
        if (getBf(curr->left) < 0) {
            curr->left = leftR(curr->left);
        }
        return rightR(curr);
    }
    else if (bf < -1) {
        if (getBf(curr->right) > 0) {
            curr->right = rightR(curr->right);
        }
        return leftR(curr);
    }

    return curr;
}

void insert() {
    char username[100];
    int job, score, match, win, lose, draw, wr;
    int num; scanf("%d", &num); getchar();

    for (int i = 0; i < num; i++) {
        scanf("%[^#]", username); getchar();
        scanf("%d", &job); getchar();
        scanf("%d", &score); getchar();
        scanf("%d", &match); getchar();
        scanf("%d", &win); getchar();
        scanf("%d", &lose); getchar();
        scanf("%d", &draw); getchar();

        root = insertNode(root, createNode(username, job, score, match, win, lose, draw));
    }
}
//================================




int counter = 0;
//================================
node* deleteNode(node* curr, int score) {
    if (!curr) return curr;
    else if (score < curr->score) {
        curr->left = deleteNode(curr->left, score);
    }
    else if (score > curr->score) {
        curr->right = deleteNode(curr->right, score);
    }
    else {
        if (curr->next) {
            node* del = curr;
            curr = curr->next;
            curr->left = del->left;
            curr->right = del->right;
            free(del); del = 0;
        }
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

                strcpy(curr->username, temp->username);
                strcpy(curr->job, temp->job);
                curr->height = temp->height;
                curr->score = temp->score;
                curr->match = temp->match;
                curr->win = temp->win;
                curr->lose = temp->lose;
                curr->draw = temp->draw;
                curr->wr = temp->wr;
                curr->next = temp->next;
                temp->next = 0;

                curr->left = deleteNode(curr->left, temp->score);
            }
        }
    }

    if (!curr) return 0;

    curr->height = getHeight(curr);
    int bf = getBf(curr);

    if (bf > 1) {
        if (getBf(curr->left) < 0) {
            curr->left = leftR(curr->left);
        }
        return rightR(curr);
    }
    else if (bf < -1) {
        if (getBf(curr->right) > 0) {
            curr->right = rightR(curr->right);
        }
        return leftR(curr);
    }

    return curr;
}

void remove() {
    int score; scanf("%d", &score); getchar();

    root = deleteNode(root, score);

    printf("\n");
}
//===============================




//===============================
void printNode(node* curr) {
    printf("Score %d\n", curr->score);
    // printf("Score %d %d %d\n", curr->score, getBf(curr), getHeight(curr));
    int i = 0;

    node* temp = curr;
    while (temp) {
        printf("%d. %s [%s] (%d%%)\n", i + 1, temp->username, temp->job, temp->wr);
        temp = temp->next;
        i++;
    }

    printf("\n");
}

void show(node* curr) {
    if (curr) {
        show(curr->left);
        printNode(curr);
        show(curr->right);
    }
}
//==============================




//==============================
int check = 0;
void showFind(node* curr, int score) {
    if (curr) {
        if (curr->score == score) {
            printNode(curr); check = 1;
        }
        showFind(curr->left, score);
        showFind(curr->right, score);
    }
}

void find() {
    int score; scanf("%d", &score); getchar();

    check = 0;
    showFind(root, score);

    if (check == 0) {
        printf("Score %d\n", score);
        printf("No data found for %d.\n", score);
        printf("\n");
    }
}
//==============================




int main()
{
    int command; scanf("%d", &command); getchar();

    root = insertNode(root, createNode("Gregor", 2, 113, 10, 9, 1, 0));
    root = insertNode(root, createNode("Heimdall", 4, 300, 100, 50, 50, 0));
    root = insertNode(root, createNode("Travy", 1, 300, 200, 100, 100, 0));
    root = insertNode(root, createNode("Tetron", 0, 300, 50, 25, 25, 0));
    root = insertNode(root, createNode("Homer", 4, 113, 10, 8, 2, 0));
    root = insertNode(root, createNode("Garen", 1, 113, 100, 70, 30, 0));

    // root = insertNode(root, createNode("Shamgar", 5, 113, 10, 10, 0, 0));
    // root = insertNode(root, createNode("CHECK 2", 1, 100, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 3", 1, 80, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 4", 1, 110, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 5", 1, 305, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 280, 100, 70, 30, 0));

    // root = insertNode(root, createNode("CHECK 6", 1, 2800, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2801, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2802, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2803, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2804, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2805, 100, 70, 30, 0));
    // root = insertNode(root, createNode("CHECK 6", 1, 2806, 100, 70, 30, 0));

    for (int i = 0; i < command; i++) {
        char str[100] = {};
        scanf("%s", str);

        if (strcmp(str, "INSERT") == 0) {
            insert();
        }
        else if (strcmp(str, "FIND") == 0) {
            find();
        }
        else if (strcmp(str, "DELETE") == 0) {
            remove();
        }
        else if (strcmp(str, "SHOWALL") == 0) {
            show(root);
        }
    }
}

/*
DaleLarsen2#3#213#804#756#47#3
HelloWorld#1#50#500#100#400#0
Tetrioc#5#213#100#90#5#5

*/