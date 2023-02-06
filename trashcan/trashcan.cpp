#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

// bebas
void test1(), test2(), test3(), test4();
// string
void test5(), test6(), test7(), test8();
// algortihm
void test9(), test10(), test11(), test12();

// supporting func
void subs(char*, int);


int main()
{
    srand(time(0));
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    test10();
}







void test1()
{
    for (int i = 0; i < 100; i++) {
        char str[200];
        scanf("%s", str);

        for (int i = 0; i < 100; i++) {
            int print = (rand() % strlen(str)) + 1;
            int print2 = (rand() % strlen(str) + 1) * 1000;
            printf("%d %d\n", print, print2);
            Sleep(100);
        }
    }   
}

void test2()
{
    char code[100] = {};

    while(1) {
        sprintf(code, "%c%c%c-%d%d%d", rand() % 26 + 65, rand() % 26 + 97, rand() % 26 + 65, rand() % 9, rand() % 9, rand() % 9);
        printf("%s\n", code);
        Sleep(200);
    }
}

void test3()
{
    FILE* file = fopen("testdata.in", "r");
    
    int min; fscanf(file, "%d\n", &min);
    char words[2000] = {};

    int counter = 0, flag = 1, page = 1;
    while (!feof(file)) {
        fscanf(file, "%s", words);
        // printf("%s\n", words);
        if (words[0] == '$') {
            // printf("Count: %d\n", counter);
            if (counter < min) { printf("page %d\n", page); flag = 0; }
            counter = 0; page++;
        } else {
            counter++;
        }
    }
    if (flag == 1) printf("Perfect\n");
}

void test4()
{
    int len = 3;
    int arr[] = { 5,3,4 };
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            // printf("%d %d\n", arr[j], arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

void test5()
{
    char str[100] = {}; scanf("%s", str); char temp[200] = {};
    int z = 0;
    for (int i = 0; i < strlen(str); i++) {
        for (int j = i; j < strlen(str); j++) {
            for (int k = i; k < j + 1; k++) {
                printf("%c", str[k]); temp[z]; z++;
            }
            puts("");
        }
    }
}

void subs(char* str, int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i + 1; j++) {
            for (int k = j; k < i+ 1; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

void test6()
{
    char str[] = "JoelEdward";
    
    subs(str, 10);
}

void test7()
{
    char str[] = { "12:43" };
    int a;
    a = (str[0] - 48) * 10;
    a += (str[1] - 48);

    if (!isdigit(str[0])) {
        printf("is not digit\n");
    } else {
        printf("is digit\n");
    }

    printf("%d\n", a);
}

int subset(int* arr, int size, int target)
{
    if (target == 0) return 1;
    if (size == 0) return 0;
    if (arr[size - 1] > target) return subset(arr, size - 1, target);
    return subset(arr, size - 1, target) || subset(arr, size - 1, target - arr[size - 1]);
}

void test8()
{
    int arr[] = { 1,2,3 };
    int size = 3; int target = 2;

    printf("%d\n", subset(arr, size, target));
}

int lower(int* arr, int size, float x)
{
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (x >= arr[mid]) low = mid + 1;
        else high = mid;
    }
    if (low < size && arr[low] <= x) low++;
    return low;
}

void test9()
{
    int arr[] = { 2,3,3,3, 5, 6 };
    int size = 6;
    float x = 4.5;
    printf("%d\n", lower(arr, size, x));
}

int search(int* arr, int find, int left, int right)
{
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == find) { return mid; }
        else if (arr[mid] < find) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void test10()
{
    int size, x; scanf("%d %d", &size, &x);
    int arr[size] = {};
    int count = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++) {
        int temp = -1;
        if (search(arr, x - arr[i], 0, size - 1) != -1) {
            if (arr[i] == temp) continue;
            count++;
            printf("%d %d\n", arr[i], arr[search(arr, x - arr[i], 0, size - 1)]);
            arr[search(arr, x - arr[i], 0, size - 1)] = 29292;
            temp = arr[i];
        }
    }
}

void test11()
{
    printf("Hello World\n");
}

void test12()
{
    
}

/*
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal) {
if (i == 0) return abs((sumTotal - sumCalculated) - sumCalculated);
return min(
findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal),
findMinRec(arr, i - 1, sumCalculated, sumTotal)); }

int findMin(int arr[], int n) n = size {
int sumTotal = 0; for (int i = 0; i < n; i++)
sumTotal += arr[i]; return findMinRec(arr, n, 0, sumTotal); }

int count(int coins[], int size, int target){
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (size <= 0) return 0;
    return count(coins, size - 1, target)
    + count(coins, size, target - coins[size - 1]);}
int main()
{
    int i, j;
    int coins[] = { 1, 2, 3 };
    int size = sizeof(coins) / sizeof(coins[0]);
    printf("%d ", count(coins, size, 4));
    getchar();
    return 0;
}





*/