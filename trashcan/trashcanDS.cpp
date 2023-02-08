#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* left;
    struct node* right;
} *root;

void test1(node*), test2(), test3(), test4();

node* createNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->val = val;
    temp->right = temp->left = 0;
    return temp;
}

node* insertNode(node* curr, node* neww) {
    if (!curr) return neww;
    else if (neww->val < curr->val) {
        curr->left = insertNode(curr->left, neww);
    }
    else if (neww->val > curr->val) {
        curr->right = insertNode(curr->right, neww);
    }
    return curr;
}

node* del(node* curr, int val) {
    if (!curr) {
        return curr;
    }
    else if (curr->val < val) {
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
    while (curr) curr = del(curr, curr->val);
}

node* search(node* curr, int val) {
    if (!curr) return curr;
    else if (curr->val == val) {
        return curr;
    }
    else if (curr->val > val) {
        return search(curr->left, val);
    }
    else {
        return search(curr->right, val);
    }
}

int main()
{
    root = insertNode(root, createNode(20));
    root = insertNode(root, createNode(25));
    root = insertNode(root, createNode(5));
    root = insertNode(root, createNode(15));
    root = insertNode(root, createNode(30));

    root = del(root, 20);
    root = delAll(root);
    node* find = search(root, 6);

    if (find) printf("%d found in tree\n", find->val);
    else printf("Not found in tree\n");

    test1(root);
}


void test1(node* curr)
{
    if (curr) {
        test1(curr->left);
        printf("%d -> ", curr->val);
        test1(curr->right);
    }
}

void test2()
{

}

void test3()
{

}

void test4()
{

}
