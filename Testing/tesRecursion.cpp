#include <stdio.h>
#include <stdlib.h>

// typedef enum boolean {TRUE, FALSE} value;

void printRev(char *str)
{
    if (*str != '\0') {
        printRev(str + 1);
        printf("%c", *str);
    } else return;
}

int length(char *str)
{
    if (*str == '\0') return 0;
    else {
        return 1 + length(str + 1);
    }
}

int sum(int a)
{
    if (a < 2) return 1;
    else {
        return a + sum(a-1);
    }
}

int gridPath(int n, int m)
{
    if (n == 1 || m == 1) return 1;
    else {
        return gridPath(n-1, m) + gridPath(n, m-1); 
    }
}

int partition(int n, int m)
{
    if (n == 0) return 1;
    else if (m == 0 || n < 0) return 0;
    else {
        return partition((n-m), m) + partition(n, m-1);
    }
}

void isPalindrome(char* str, int a, int len)
{
    if (str[a] == str[len]) {
        if (a + 1 == len || a == len) {
            printf("Is a palindrome.\n");
            return;
        }

        isPalindrome(str, a + 1, len - 1);
        
    } else {
        printf("Is not a palindrome.\n");
    }
}

int main()
{
    char str[255] = {};
    // int a = 1;
    scanf("%s", str);
    // printRev(str);
    // printf("%d", length(str));

    // int hasil = sum(10);
    // printf("%d\n", hasil);
    // int path = gridPath(3,10);
    // printf("%d\n", path);
    // int part = partition(9,5);
    // printf("%d\n", part);
    isPalindrome(str, 0, length(str) - 1);
}