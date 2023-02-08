#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    Node* left, *right;
} *root;

Node* createNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->left = temp->right = 0;
    return temp;
}

Node* insertNode(Node* curr, Node* node) {
    if (!curr) return node;
    else if (node->val < curr->val) {
        curr->left = insertNode(curr->left, node);
    }
    else if (node->val > curr->val) {
        curr->right = insertNode(curr->right, node);
    }
    return curr;
}

Node* deleteNode(Node* curr, int val) {
    if (!curr) {
        return curr;
    }
    else if (val < curr->val) {
        curr->left = deleteNode(curr->left, val);
    }
    else if (val > curr->val) {
        curr->right = deleteNode(curr->right, val);
    }
    else {
        if (!curr->left && !curr->right) {
            free(curr);
            curr = 0;
        }
        else if (!curr->left) {
            Node* temp = curr;
            curr = curr->right;
            free(temp);
            temp = 0;
        }
        else if (!curr->right) {
            Node* temp = curr;
            curr = curr->left;
            free(temp);
            temp = 0;
        }
        else {
            // predecessor
            Node* temp = curr->left;
            while (temp->right) {
                temp = temp->right;
            }
            curr->val = temp->val;
            curr->left = deleteNode(curr->left, temp->val);

            // successor
            // Node* temp = curr->right;
            // while (temp->left) {
            //     temp = temp->left;
            // }
            // curr->val = temp->val;
            // curr->right = deleteNode(curr->right, temp->val);
        }
    }
    return curr;
}

Node* deleteAll(Node* curr) {
    if (!curr) return curr;
    while (curr) curr = deleteNode(curr, curr->val);
}

Node* searchNode(Node* curr, int val) {
    if (!curr) return curr;
    else if (val == curr->val) {
        return curr;
    }
    else if (val < curr->val) {
        return searchNode(curr->left, val);
    }
    else {
        return searchNode(curr->right, val);
    }
}

void preFix(Node*), inFix(Node*), postFix(Node*);

int main()
{
    root = insertNode(root, createNode(20));
    root = insertNode(root, createNode(10));
    root = insertNode(root, createNode(5));
    root = insertNode(root, createNode(15));
    root = insertNode(root, createNode(30));
    root = insertNode(root, createNode(40));

    // root = deleteNode(root, 20);
    // root = deleteNode(root, 10);
    // root = deleteNode(root, 5);
    // root = deleteNode(root, 15);
    // root = deleteNode(root, 30);
    // root = deleteNode(root, 40);
    // root = deleteAll(root);

    inFix(root);
}


void preFix(Node* curr) {
    if (!curr) return;
    printf("%d ", curr->val);
    preFix(curr->left);
    preFix(curr->right);
}

void inFix(Node* curr) {
    if (!curr) {
        // printf("Not\n");
        return;
    }
    inFix(curr->left);
    printf("%d ", curr->val);
    inFix(curr->right);
}

void postFix(Node* curr) {
    if (!curr) return;
    postFix(curr->left);
    postFix(curr->right);
    printf("%d ", curr->val);
}