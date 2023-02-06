#include <stdio.h>

void move(int, char, char, char);

int main()
{
    int num;
    printf("Enter the number of plates: ");
    scanf("%d", &num);
    move(num, 'L', 'M', 'R');

    return 0;
}

void move(int num, char dari, char to, char temp)
{
    if (num == 1);
}

/*
move 3 to m
move 2 to m
move 1 to m
move 4 to r
move 2 to l
move 1 to l
move 3 to r
move 1 to m
move 2 to r
move 1 to r
*/