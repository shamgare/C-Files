#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// binary search tree

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

node* root = 0;

node* createNode (int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = 0;
    return temp;
}

void search(node* curr, int find)
{
    if (!curr) {
        printf("%d is not found in BST\n", find);
        return;
    }
    if (curr->val == find) {
        printf("%d is found in BST\n", curr->val);
        return;
    }
    if (curr->val < find) return search(curr->right, find);
    else return search(curr->left, find);
}

void insert(node* curr, int val)
{
    if (root == 0) {
        root = createNode(val);
    }
    else {
        if (curr->val > val && curr->left == 0) {
            curr->left = createNode(val);
        }
        else if (val > curr->val && curr->right == 0) {
            curr->right = createNode(val);
        }
        else if (curr->val < val) {
            insert(curr->right, val);
        }
        else if (curr->val > val) {
            insert(curr->left, val);
        }
    }
}

node* delRecursive(node* parent, node* curr)
{
    // if curr is leaf
    if (!curr->left && !curr->right) {
        // if there is only 1 node in BST ====================================
        if (root == curr) {
            root = 0;
        }
        free(curr);
        return 0;
    }
    // if 1 left child
    else if (curr->left && !curr->right) {
        node* temp = curr->left;
        if (curr->val < parent->val) {
            parent->left = temp;
        }
        else {
            parent->right = temp;
        }
        return temp;
    }
    // if 1 right child
    else if (!curr->left && curr->right) {
        node* temp = curr->right;
        if (curr->val < parent->val) {
            parent->left = temp;
        }
        else {
            parent->right = temp;
        }
        return temp;
    }
    // if 2 children
    else {
        node* t = curr->left;
        node* tParent = curr;

        while (t->right) {
            tParent = t;
            t = t->right;
        }
        
        curr->val = t->val;

        if (tParent->left == t) {
            tParent->left = t->left;
        }
        else {
            tParent->right = t->left;
        }
        
        return curr;
    }
}

node* parent = 0; // parent dari node yang di delete (curr)

void del(node* curr, int deleteVal)
{
    if (!curr) {
        printf("%d is not available to delete\n", deleteVal);
        return;
    }
    if (curr->val == deleteVal) {
        curr = delRecursive(parent, curr);
        // if (deleteVal > parent->val) parent->right = curr; ==========================
        // else parent->left = curr;
        return;
    }
    // traversal
    if (deleteVal < curr->val) {
        parent = curr;
        del(curr->left, deleteVal);
    }
    else if (deleteVal > curr->val) {
        parent = curr;
        del(curr->right, deleteVal);
    }
}

void displayInfix(node* curr)
{
    // infix
    if (curr->left) displayInfix(curr->left);
    printf("%d ", curr->val);
    if (curr->right) displayInfix(curr->right);
}

int main()
{
    insert(root, 10);
	insert(root, 20);
	insert(root, 9);
	insert(root, 5);
	insert(root, 11);
	insert(root, 1);
	insert(root, 12);
	insert(root, 25);
	insert(root, 30);
	insert(root, 35);
	insert(root, 40);

    displayInfix(root);
    printf("\n");
    
    // search(root, 3);
    // search(root, 100);
    // search(root, 7);

    del(root, 10);
    displayInfix(root);
    printf("\n");

    return 0;
}