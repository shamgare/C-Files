#include <stdio.h>

void bubble(int*, int), bentuk(), selection(int*, int);
void insertion(int*, int);

int main()
{
    int arr[] = {3,6,2,8,65,3,6,8,54}; 
    int len = sizeof(arr) / sizeof(arr[0]);
    //==========================================

    //bentuk();
    bubble(arr, len);
    //selection(arr, len);
    //insertion(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
    return 0;
}





















void insertion(int* arr, int len)
{
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void selection(int* arr, int len)
{
    int temp;
    for (int i = 0; i < len - 1; i++) {
        int min = i;

        for (int j = i+1; j < len; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void bubble(int *arr, int len)
{
    int temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            } 
        }
    }
}
















void bentuk()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j > i) printf(" ");
            else printf("%d", j+1);
            // printf("%d", j+1);
        }
        puts("");
    }
    puts("");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j < i) printf(" ");
            else printf("%d", j+1);
            // printf("%d", j+1);
        }
        puts("");
    }
    puts("");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j < 8-i) printf("%d", j+1);
            else printf(" ");
        }
        puts("");
    }
    puts("");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j >= 8-i-1) printf("%d", j+1);
            else printf(" ");
        }
        puts("");
    }
}