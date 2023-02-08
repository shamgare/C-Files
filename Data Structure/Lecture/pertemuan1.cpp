#include <stdio.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

int main()
{
    int n = 9;
    int* pn = &n;

    printf("Value of n : %d\n", n);
    printf("Address of n : %d\n", &n);
    
    printf("Value of pn : %d\n", *pn);
    printf("Address of n : %d\n", pn);

    *pn = 70;
    
    printf("New value of n : %d\n", n);
}