#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[100];
    int height;
    struct node* left, * right;
} node;

node* root = 0;

node* createNode(char* name) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->height = 1;
    temp->left = temp->right = 0;
    return temp;
}

int getMax(int a, int b) {
    return a <= b ? b : a;
}
int getHeight(node* curr) {
    return !curr ? 0 : 1 + getMax(getHeight(curr->left), getHeight(curr->right));
}
int getBf(node* curr) {
    return !curr ? 0 : getHeight(curr->left) - getHeight(curr->right);
}

node* rightRotate(node* curr) {
    node* newP = curr->left;
    curr->left = newP->right;
    newP->right = curr;

    curr->height = getHeight(curr);
    newP->height = getHeight(newP);

    return newP;
}
node* leftRotate(node* curr) {
    node* newP = curr->right;
    curr->right = newP->left;
    newP->left = curr;

    curr->height = getHeight(curr);
    newP->height = getHeight(newP);

    return newP;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (strcmp(neww->name, curr->name) < 0) curr->left = insertNode(curr->left, neww);
    else if (strcmp(neww->name, curr->name) > 0) curr->right = insertNode(curr->right, neww);

    curr->height = getHeight(curr);
    int bf = getBf(curr);

    if (bf > 1) {
        if (getBf(curr->left) < 0) {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (bf < -1) {
        if (getBf(curr->right) > 0) {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }

    return curr;
}

node* deleteNode(node* curr, char* name) {
    if (!curr) return curr;
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
            while (temp && temp->right) temp = temp->right;

            strcpy(curr->name, temp->name);
            curr->height = temp->height;

            curr->left = deleteNode(curr->left, temp->name);
        }
    }

    if (!curr) return 0;

    curr->height = getHeight(curr);
    int bf = getBf(curr);

    if (bf > 1) {
        if (getBf(curr->left) < 0) {
            curr->left = leftRotate(curr->left);
        }
        return rightRotate(curr);
    }
    else if (bf < -1) {
        if (getBf(curr->right) > 0) {
            curr->right = rightRotate(curr->right);
        }
        return leftRotate(curr);
    }

    return curr;
}

int main()
{

}