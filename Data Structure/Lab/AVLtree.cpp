#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[105];
    int price;
    int id;
    int height;
    int bf;
    struct node* left;
    struct node* right;
} node;

node* createNode(const char* name, int price) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->price = price;
    temp->height = 1;
    temp->left = temp->right = 0;
    return temp;
}

int getMax(int a, int b) {
    return a > b ? a : b;
}
int getHeight(node* curr) {
    return !curr ? 0 : 1 + getMax(getHeight(curr->left), getHeight(curr->right));
}
int getBf(node* curr) {
    return !curr ? 0 : (getHeight(curr->left) - getHeight(curr->right));
}

node* rightRotate(node* curr) {
    node* newParent = curr->left;
    curr->left = newParent->right;
    newParent->right = curr;

    curr->height = getHeight(curr);
    newParent->height = getHeight(newParent);

    return newParent;
}

node* leftRotate(node* curr) {
    node* newParent = curr->right;
    curr->right = newParent->left;
    newParent->left = curr;

    curr->height = getHeight(curr);
    newParent->height = getHeight(newParent);

    return newParent;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->price < curr->price) curr->left = insertNode(curr->left, neww);
    else if (neww->price > curr->price) curr->right = insertNode(curr->right, neww);

    curr->height = getHeight(curr);

    int bal = getBf(curr);

    if (bal > 1) {
        // if price > curr->price
        // L
        if (neww->price > curr->left->price) curr->left = leftRotate(curr->left);
        // R
        return rightRotate(curr);
    }
    else if (bal < -1) {
        // if price < curr->price
        // R
        if (neww->price < curr->right->price) curr->right = rightRotate(curr->right);
        // L
        return leftRotate(curr);
    }

    return curr;
}

node* updateNode(node* curr, int price, const char* name) {
    if (!curr) {
        printf("Data Not Found!\n\n");
        return curr;
    }
    else if (price < curr->price) curr->left = updateNode(curr->left, price, name);
    else if (price > curr->price) curr->right = updateNode(curr->right, price, name);
    else {
        printf("Data Updated!\n\n");
        strcpy(curr->name, name);
    }
    return curr;
}

node* deleteNode(node* curr, int price) {
    if (!curr) return curr;
    else if (price < curr->price) curr->left = deleteNode(curr->left, price);
    else if (price > curr->price) curr->right = deleteNode(curr->right, price);
    else {
        if (!curr->left && !curr->right) {

        }
        else if (!curr->left) {

        }
        else if (!curr->right) {

        }
        else {

        }
    }
}

void inOrder(node* curr) {
    if (curr) {
        inOrder(curr->left);
        printf("%s - %drb - %d - %d\n", curr->name, curr->price, curr->height, getBf(curr));
        inOrder(curr->right);
    }
}
void preOrder(node* curr) {
    if (curr) {
        printf("%s - %drb - %d - %d\n", curr->name, curr->price, curr->height, getBf(curr));
        inOrder(curr->left);
        inOrder(curr->right);
    }
}

int main()
{
    node* root = 0;

    root = insertNode(root, createNode("Sate Kambing", 40));
    root = insertNode(root, createNode("Sate Babi", 37));
    root = insertNode(root, createNode("Sate Buaya", 35));
    root = insertNode(root, createNode("Sate Padang", 34));
    root = insertNode(root, createNode("Soto Ayam", 30));
    root = insertNode(root, createNode("Soto Banjar", 10));
    root = insertNode(root, createNode("Soto Ayam", 29));
    root = insertNode(root, createNode("Soto Ayam", 89));
    root = insertNode(root, createNode("Soto Ayam", 79));
    // root = insertNode(root, createNode("Soto Ayam", 60));
    // root = insertNode(root, createNode("Sate Kuda", 10));

    inOrder(root);

    // root = updateNode(root, 20, "Soto Babi");

    // inOrder(root);

    return 0;
}