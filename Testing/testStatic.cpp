#include <stdio.h>
#include <stdlib.h>

extern char str[];

void print()
{
    static int count = 0;
    printf("Count: %d\n", count++);
    int count2 = 0;
    printf("Count 2: %d\n", count2++);
}

int main(/* int arg, char *argv[] */)
{
    int i;
    for (int i = 0; i < 5; i++) {
        print();
    }
    for (int i = 0; i < 3; i++) {
        print();
    }
    
    system("date");
    // printf("%s\n", str);


    // scanf aru inisialisaisi dgn mallow

    // print address arr biasa vs malloc

    return 0;
}