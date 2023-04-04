#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 100

typedef struct node {
    char name[100];
    int price;
} node;

node nodes[maxSize];
int index = 1;

// struct Heap {
//     node* nodess;
//     int capacity;
//     int lastIndex;
// } heap;

// void initializeHeap() {
//     heap = { NULL, 2, 1 };
//     heap.nodess = (node*)malloc(sizeof(node)) * heap.capacity;
//     return;
// }
// void resizeHeap() {
//     heap.nodess = (node*)realloc(heap.nodess, sizeof(node) * heap.capacity);
//     return;
// }

void swap(node* a, node* b) {
    node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int curr, int size) {
    int left = curr * 2;
    int right = left + 1;

    int largest = curr;

    if (left < size && nodes[left].price > nodes[largest].price) {
        largest = left;
    }
    if (right < size && nodes[right].price > nodes[largest].price) {
        largest = right;
    }
    if (largest != curr) {
        swap(&nodes[largest], &nodes[curr]);
        heapify(largest, size);
    }
}

void buildHeap() {
    for (int i = index / 2; i >= 1; i--) {
        heapify(i, index);
    }
}

void view() {
    for (int i = 1; i < index; i++) {
        printf("%s - %d\n", nodes[i].name, nodes[i].price);
    }
    printf("\n");
}

int search(int price) {
    for (int i = 1; i < index; i++) {
        if (nodes[i].price == price) {
            return i;
        }
    }
    return -1;
}

void deleteNode(int price) {
    int idx = search(price);

    if (idx == -1) {
        return;
    }

    swap(&nodes[idx], &nodes[index - 1]);
    index--;
    buildHeap();
}

void insert(const char* name, int price) {
    // if (heap.lastIndex == heap.capacity) {
    //     resizeHeap();
    // }

    strcpy(nodes[index].name, name);
    nodes[index].price = price;
    index++;
    buildHeap();
}

void heapSort() {
    buildHeap();

    for (int i = index - 1; i > 1; i--) {
        swap(&nodes[1], &nodes[i]);
        heapify(1, i);
    }
}

int main()
{
    // initializeHeap();

    insert("Sapi", 30000);
    insert("Ayam", 28000);
    insert("Bebek", 37000);
    insert("Bebek", 42000);
    insert("Bebek", 76000);
    view();

    heapSort();
    printf("After Sort:\n");
    view();

    // deleteNode(30000);
    // view();
}