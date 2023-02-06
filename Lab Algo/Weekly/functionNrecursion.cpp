#include <stdio.h>

void printMenu()
{
    puts("Menu");
    puts("1. Insert Data");
    puts("2. View Data");
}

int sum(int a, int b)
{
    return a + b;
}

int power(int initialValue, int powerValue)
{
    int result = 1;
    for (int i = 0; i < powerValue; i++) {
        result = result * initialValue;
    }
    return result;
}

void scanTwoNumbers(int *firstNumber, int *secondNumber)
{
    scanf("%d %d", firstNumber, secondNumber);
}

int factorial(int value)
{
    if (value == 0) return 1;
    return value * factorial(value-1);
}

int main()
{
    int angkaPertama = 2, angkaKedua = 3, hasilPenjumlahan, hasilPangkat, factorialResult;
    int firstNumber = 0, secondNumber = 0;

    printMenu();

    hasilPenjumlahan = sum(angkaPertama,angkaKedua);
    printf("Hasil: %d\n", hasilPenjumlahan);

    hasilPangkat = power(hasilPenjumlahan, 3);
    printf("Hasil Pangkat 3: %d\n", hasilPangkat);

    scanTwoNumbers(&firstNumber, &secondNumber);
    printf("%d %d\n", firstNumber, secondNumber);

    factorialResult = factorial(5);
    printf("%d", factorialResult);
    return 0;
}