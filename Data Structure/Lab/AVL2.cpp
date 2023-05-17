#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[105];
    int price;
    int id;
    int height;
    struct node* left;
    struct node* right;
} node;

int getMax(int a, int b) {
    return a >= b ? a : b;
}
int getHeight(node* curr) {
    return !curr ? 0 : 1 + getMax(getHeight(curr->left), getHeight(curr->right));
}
int getBf(node* curr) {
    return !curr ? 0 : getHeight(curr->left) - getHeight(curr->right);
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

node* createNode(int id, const char* name, int price) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->price = price;
    temp->id = id;
    temp->height = 1;
    temp->left = temp->right = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->id < curr->id) curr->left = insertNode(curr->left, neww);
    else if (neww->id >= curr->id) curr->right = insertNode(curr->right, neww);

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

node* deleteNode(node* curr, int id) {
    if (!curr) return curr;
    else if (id < curr->id) curr->left = deleteNode(curr->left, id);
    else if (id > curr->id) curr->right = deleteNode(curr->right, id);
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
            curr->id = temp->id;
            curr->price = temp->price;

            curr->left = deleteNode(curr->left, temp->id);
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

void view(node* curr) {
    if (curr) {
        view(curr->left);
        printf("%-3d %-50s %-6d (Height: %d) (BF: %d)\n", curr->id, curr->name, curr->price, curr->height, getBf(curr));
        view(curr->right);
    }
}

int main()
{
    node* root = 0;

    root = insertNode(root, createNode(40, "Bakso", 20000));
    root = insertNode(root, createNode(37, "Mie Ayam", 15000));
    root = insertNode(root, createNode(35, "Salad", 10000));
    root = insertNode(root, createNode(34, "Kari", 15000));
    root = insertNode(root, createNode(30, "Nasi Uduk", 18000));
    root = insertNode(root, createNode(10, "Nasi Ulam", 24000));
    root = insertNode(root, createNode(29, "Nasi Krabu", 30000));
    root = insertNode(root, createNode(89, "Nasi Goreng", 15000));
    root = insertNode(root, createNode(79, "Nasi Kuning", 40000));

    // root = deleteNode(root, 10);

    view(root);

    return 0;
}

/*

    // if (bf > 1) {
    //     if (neww->id > curr->left->id) {
    //         curr->left = leftRotate(curr->left);
    //     }
    //     return rightRotate(curr);
    // }
    // else if (bf < -1) {
    //     if (neww->id < curr->right->id) {
    //         curr->right = rightRotate(curr->right);
    //     }
    //     return leftRotate(curr);
    // }

*/