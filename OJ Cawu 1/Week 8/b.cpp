#include <stdio.h>
#include <math.h>

int main()
{
    int pangkat;
    scanf("%d", &pangkat);
    long long int hasil = pow(2, pangkat);
    printf("%lld\n", hasil - 1);
}