#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
} *root;

node* createNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = 0;
    return temp;
}

node* insert(node* curr, node* neww) {
    if (!curr) return neww;
    else if (curr->val < neww->val) {
        curr->right = insert(curr->right, neww);
    }
    else if (curr->val > neww->val) {
        curr->left = insert(curr->left, neww);
    }
    return curr;
}

node* del(node* curr, int val) {
    if (!curr) return curr;
    
    if (curr->val < val) {
        curr->right = del(curr->right, val); 
    }
    else if (curr->val > val) {
        curr->left = del(curr->left, val);
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
            while (temp->right) {
                temp = temp->right;
            }
            curr->val = temp->val;
            curr->left = del(curr->left, temp->val);
        }
    }
    return curr;
}

node* delAll(node* curr) {
    if (!curr) return curr;
    while (curr) del(curr, curr->val);
}

node* search(node* curr, int val) {
    if (!curr) return curr;
    if (curr->val == val) {
        return curr;
    }
    else if (curr->val < val) {
        return search(curr->right, val);
    }
    else {
        return search(curr->left, val);
    }
}

void view(node* curr) {
    if (curr) {
        view(curr->left);
        printf("%d -> ", curr->val);
        view(curr->right);
    }
}

int main()
{
    root = insert(root, createNode(30));
    root = insert(root, createNode(20));
    root = insert(root, createNode(40));
    root = insert(root, createNode(10));
    root = insert(root, createNode(60));
    root = insert(root, createNode(90));

    view(root);
}