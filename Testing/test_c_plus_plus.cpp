#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char name[388];
    scanf("%s", name);
    cout << name; cout << ", hello world!\n";
    printf("hello world!, %s.\n", name);

    return 0;
}