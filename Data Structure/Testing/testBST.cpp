#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char name[40];
    struct node* left;
    struct node* right;
};

node* root;

node* createNode(const char* name) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->left = temp->right = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (strcmp(neww->name, curr->name) < 0) {
        curr->left = insertNode(curr->left, neww);
    }
    else {
        curr->right = insertNode(curr->right, neww);
    }
    return curr;
}

node* deleteNode(node* curr, const char* name) {
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
            while (temp->right) temp = temp->right;
            strcpy(curr->name, temp->name);
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

void view(node* curr) {
    if (curr) {
        view(curr->left);
        printf("%s -> ", curr->name);
        view(curr->right);
    }
}

int main()
{
    root = insertNode(root, createNode("Javier"));
    root = insertNode(root, createNode("Abdhy"));
    root = insertNode(root, createNode("Daniel"));
    root = insertNode(root, createNode("Yoga"));
    root = insertNode(root, createNode("Jacky"));
    root = insertNode(root, createNode("Ferren"));
    root = insertNode(root, createNode("Ichsan"));
    root = insertNode(root, createNode("Ghoran"));

    root = deleteNode(root, "Javier");

    // struct node* find = search(root, "Ichsan");

    view(root);
}