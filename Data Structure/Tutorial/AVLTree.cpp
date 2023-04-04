#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int val;
    int height;
    struct node* left;
    struct node* right;
} node;

node* root = 0;

node* createNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->height = 1;
    temp->left = temp->right = 0;
    return temp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(node* curr) {
    if (!curr) return 0;
    return curr->height;
}

int getBf(node* curr) {
    if (!curr) return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

node* rightRotation(node* t) {
    node* s = t->left;
    node* b = s->right;

    t->left = b;
    s->right = t;

    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));

    return s;
}

node* leftRotation(node* t) {
    node* s = t->right;
    node* b = s->left;

    t->right = b;
    s->left = t;

    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));

    return s;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->val < curr->val) curr->left = insertNode(curr->left, neww);
    else if (neww->val > curr->val) curr->right = insertNode(curr->right, neww);
    else return curr;

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBf(curr);

    //LL
    if (bf > 1 && getBf(curr->left) >= 0) {
        return rightRotation(curr);
    }
    //RR
    if (bf < -1 && getBf(curr->right) <= 0) {
        return leftRotation(curr);
    }
    //LR
    if (bf > 1 && getBf(curr->left) < 0) {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }
    //RL
    if (bf < -1 && getBf(curr->right) > 0) {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }

    return curr;
}

node* deleteNode(node* curr, int val) {
    if (!curr) return curr;
    else if (val < curr->val) curr->left = deleteNode(curr->left, val);
    else if (val > curr->val) curr->right = deleteNode(curr->right, val);
    else {
        if (!curr->left && !curr->right) {
            free(curr); curr = 0;
            return curr;
        }
        else if (!curr->right) {
            node* temp = curr;
            curr = curr->left;
            free(temp); temp = 0;
            return curr;
        }
        else if (!curr->left) {
            node* temp = curr;
            curr = curr->right;
            free(temp); temp = 0;
            return curr;
        }
        else {
            node* temp = curr->left;
            while (temp->right) temp = temp->right;
            curr->val = temp->val;
            curr->left = deleteNode(curr->left, temp->val);
        }
    }
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBf(curr);

    //LL
    if (bf > 1 && getBf(curr->left) >= 0) {
        return rightRotation(curr);
    }
    //RR
    if (bf < -1 && getBf(curr->right) <= 0) {
        return leftRotation(curr);
    }
    //LR
    if (bf > 1 && getBf(curr->left) < 0) {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }
    //RL
    if (bf < -1 && getBf(curr->right) > 0) {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }

    return curr;
}

void view(node* curr) {
    if (curr) {
        printf("%d -> ", curr->val);
        view(curr->left);
        view(curr->right);
    }
}

void peek() {
    if (root) printf("\nRoot: %d\n\n", root->val);
}

int main()
{
    root = insertNode(root, createNode(70));
    root = insertNode(root, createNode(80));
    root = insertNode(root, createNode(90));
    root = insertNode(root, createNode(100));
    root = insertNode(root, createNode(50));

    view(root);
    peek();

    root = deleteNode(root, 80);
    view(root);
    peek();
    root = deleteNode(root, 50);
    view(root);
    peek();
    root = deleteNode(root, 90);
    view(root);
    peek();

    return 0;
}