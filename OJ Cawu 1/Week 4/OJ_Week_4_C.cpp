#include <stdio.h>
#include <string.h>

int main()
{
    int kasus, i, k, x;
    char str[1050];
    
    scanf("%d", &kasus);
    getchar();
    
    for (i=0;i<kasus;i++) {
    	
        scanf("%s", str);
        getchar();
        printf("Case #%d : ", i+1);
        x = strlen(str)-1;
        
        for (k=0;k<strlen(str);k++) {
        	printf("%c", str[x]);
        	x--;
		}
		printf("\n");
    }

    return 0;
}
