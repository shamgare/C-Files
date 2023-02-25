#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct node {
    char name[100];
    struct node* left;
    struct node* right;
} node;

node* root;

node* createNode(char* name) {
    node* temp = (node*)malloc(sizeof(node));
    strcpy(temp->name, name);
    temp->left = temp->right = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (strcmp(neww->name, curr->name) < 0) curr->left = insertNode(curr->left, neww);
    else if (strcmp(neww->name, curr->name) > 0) curr->right = insertNode(curr->right, neww);
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
            while (temp->right) {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

node* search1(node* curr, char* name) {
    if (!curr || strcmp(curr->name, name) == 0) return curr;
    else if (strcmp(name, curr->name) < 0) return search1(curr->left, name);
    else if (strcmp(name, curr->name) > 0) return search1(curr->right, name);
}

int main()
{

}