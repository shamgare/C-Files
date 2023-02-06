#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("Epo Anjing\n");
    isupper();
    return 0;
}

int isupper() 
{
    char babi[5] = "babi";
    toupper(babi);
    printf("%s", babi);
}