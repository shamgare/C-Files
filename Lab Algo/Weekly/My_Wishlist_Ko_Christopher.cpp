#include <stdio.h>
#include <string.h>

int main()
{
    int prices[20];
    char names[20][50];
    int last_index = 0;
    int input = 0;

    do
    {
	    puts("My Wishlist");
	    puts("+====================================+");
        printf("| %-15s | %-15s |\n", "Item Name", "Item Price");
	    puts("+====================================+");
	    
	    if (last_index == 0) {
            puts("Need you to fill it :)");
        }
        for (int i = 0; i < last_index; i++) {
            printf("| %-15s | Rp.%-12d |\n", names[i], prices[i]);
        }

	    puts("+====================================+");
        puts("1. Add item");
        puts("2. Exit");
        printf(">> "); 
        scanf("%d", &input); 
        getchar();

        switch (input) {
        case 1:
            // ambil input item name
            char name[50];
            printf("Input item name: ");
            scanf("%[^\n]",name);

            // ambil input item price
            int price;
            printf("Input item price: ");
            scanf("%d", &price);

            // masukkin item name dan item price ke dalam array
            prices[last_index] = price;
            strcpy(names[last_index], name);

            // menambahkan last index
            last_index++;
            break;

        case 2:
            printf("Thank you :D");
            break;
        }
        
    } while (input != 2);
    
	return 0;
}
