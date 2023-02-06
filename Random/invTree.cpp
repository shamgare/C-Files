#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;


Node* create_node(int value) {
    // Allocate enough memory four our node struct
    Node* n = malloc(sizeof(Node));    

    // Exit if the allocation failed
    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Populate the node with values and return it
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void invert_tree(Node* node) {
    // Check whether the node "exists"
    if (node == NULL) {
        return;
    }

    // Swap left and right children
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recursively call the function on the children
    invert_tree(node->left);
    invert_tree(node->right);
}


void print_tree(Node* root, int space) {
    if (root == NULL)
        return;

    space += 3;

    // Print the right child first, recursively
    print_tree(root->right, space);

    // Print spaces to signify recursion depth
    for (int i = 3; i <= space; i++) {
        printf(" ");
    }

    // Print the root value
    printf("%d\n", root->value);

    // Print the left child, recursively
    print_tree(root->left, space);
}


void free_memory(Node* root) {
    if (root == NULL) {
        return;
    }
    free_memory(root->left);
    free_memory(root->right);
    free(root);
}


int main(void) {

    // Create the tree
    Node* root = create_node(3);

    root->left = create_node(2);
    root->right = create_node(5);

    root->left->left = create_node(1);
    root->left->right = create_node(6);

    root->right->left = create_node(7);
    root->right->right = create_node(4);

    // Print the tree before inverting it
    printf("Before inversion:\n");
    print_tree(root, 0);
    printf("\n");

    invert_tree(root);

    // Print the tree after inverting it
    printf("After inversion:\n");
    print_tree(root, 0);

    free_memory(root);

    return 0;
}