#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

int main(int argc, char* argv[])
{
    Node root;
    
    root.x = 15;
    root.next = (Node*)malloc(sizeof(Node));
    
    root.next->x = -14;
    root.next->next = (Node*)malloc(sizeof(Node));

    root.next->next->x = 20;
    root.next->next->next = (Node*)malloc(sizeof(Node));
    
    root.next->next->next->x = 40;
    root.next->next->next->next = NULL;

    Node* curr = &root;
    
    while (curr != NULL) {
        printf("%d\n", curr->x);
        curr = curr->next;
    }

    

    // printf("First : %d\n", root.x);
    
    // printf("Second : %d\n", root.next->x);
    // printf("Second : %d\n", (*root.next).x);

    free(root.next->next->next);
    free(root.next->next);
    free(root.next);
    
    return 0;
}
