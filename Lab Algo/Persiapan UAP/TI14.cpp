#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct movies {
    char id[10];
    char name[200];
    int startA;
    int startB;
    int endA;
    int endB;
    int dur;
    int studio;
} movies[100];

char start[5];
char end[5];
int movieCount = 0;

void swap(int a, int b)
{
    struct movies temp = movies[a];
    movies[a] = movies[b];
    movies[b] = temp;
}

int part(int low, int high)
{
    int i = low - 1;
    int j = low;
    int pivot = movies[high].dur;

    while (j < high) {
        if (movies[j].dur <= pivot) {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);

    return i + 1;
}

void qs(int low, int high)
{
    if (low < high) {
        int pos = part(low, high);

        qs(low, pos - 1);
        qs(pos + 1, high);
    }
}

void importData()
{
    FILE* file = fopen("cinema.csv", "r");

    if (file == NULL) return;

    while (!feof(file)) {
        fscanf(file, "%[^,],%[^,],%2d:%2d,%2d:%2d,%d\n", movies[movieCount].id, movies[movieCount].name, &movies[movieCount].startA, &movies[movieCount].startB, &movies[movieCount].endA, &movies[movieCount].endB, &movies[movieCount].studio);
        
        movies[movieCount].dur = movies[movieCount].endA - movies[movieCount].startA;
        movies[movieCount].dur *= 60;
        
        if (movies[movieCount].endB == 0) {
            if (movies[movieCount].startB == 0) {
                movies[movieCount].dur += 60 - movies[movieCount].startB;
                movies[movieCount].dur -= 60;
            } else {
                movies[movieCount].dur += 60 - movies[movieCount].startB;
                movies[movieCount].dur -= 60;
            }
        } else movies[movieCount].dur += movies[movieCount].endB - movies[movieCount].startB;
        
        movieCount++;
    }

    fclose(file);
}

void displayHeader()
{
    system("cls");
    puts("=================================================================================================================");
    puts("|  .oooooo.    o8o                                                         ooooooo  ooooo ooooo oooooo     oooo |");
    puts("| d8P'  `Y8b   `\"'                                                          `8888    d8'  `888'  `888.     .8'  |");
    puts("|888          oooo  ooo. .oo.    .ooooo.  ooo. .oo.  .oo.    .oooo.           Y888..8P     888    `888.   .8'   |");
    puts("|888          `888  `888P\"Y88b  d88' `88b `888P\"Y88bP\"Y88b  `P  )88b           `8888'      888     `888. .8'    |");
    puts("|888           888   888   888  888ooo888  888   888   888   .oP\"888          .8PY888.     888      `888.8'     |");
    puts("|`88b    ooo   888   888   888  888    .o  888   888   888  d8(  888         d8'  `888b    888       `888'      |");
    puts("| `Y8bood8P' 'o888o o888o o888o `Y8bod8P' 'o888o o888o o888o `Y8888o      o888o   o88888o o888o       `8'       |");
    puts("=================================================================================================================");
    puts("");
    puts("Hi There!");
    puts("1. View All Movie");
    puts("2. Add New Movie");
    puts("3. Update Movie");
    puts("4. Delete Movie");
    puts("5. Save and Exit");
}

void viewAll()
{
    system("cls");

    qs(0, movieCount - 1);
    
    if (movieCount == 0) {
        puts("No movie yet..."); return;
    } else {
        puts("+=======================================================================================================+");
        puts("| No. | Movie ID |        Movie Name        | Start Time  | End Time    |    Movie Duration    | Studio |");
        puts("+=======================================================================================================+");
        for (int i = 0; i < movieCount; i++) {
            printf("| %-3d | %-8s | %24s |    %02d:%02d    |    %02d:%02d    |     %4d Minutes     | %6d |\n", i+1, movies[i].id, movies[i].name, movies[i].startA, movies[i].startB, movies[i].endA, movies[i].endB, movies[i].dur, movies[i].studio);
        }
        puts("+=======================================================================================================+");
    }
}

void addMenu()
{
    system("cls");
    
    int check;

    do {
        printf("Enter movie name [1 - 20 chars]: ");
        scanf("%[^\n]", movies[movieCount].name); getchar();
        if (strlen(movies[movieCount].name) < 1 || strlen(movies[movieCount].name) > 20) {
            printf("Movie name must be between 1-20 characters!"); getchar();
        }
    } while (strlen(movies[movieCount].name) < 1 || strlen(movies[movieCount].name) > 20);

    //validasi
    do {
        printf("Enter movie start time [HH:MM]: ");
        scanf("%s", start); getchar();

        check = 0;

        if (strlen(start) != 5) check = 1;
        if (start[2] != ':') check = 1;
        if (!isdigit(start[0]) || !isdigit(start[1])) check = 1;
        if (!isdigit(start[3]) || !isdigit(start[4])) check = 1;

        movies[movieCount].startA = (start[0] - 48) * 10;
        movies[movieCount].startA += (start[1] - 48);
        
        movies[movieCount].startB = (start[3] - 48) * 10;
        movies[movieCount].startB += (start[4] - 48);

        if (movies[movieCount].startA < 0 || movies[movieCount].startA > 23) check = 1;
        if (movies[movieCount].startB < 0 || movies[movieCount].startB > 59) check = 1;
        if (movies[movieCount].startA == 23 && movies[movieCount].startB == 59) check = 1;
        
        if (check == 1) printf("Invalid Time Format!\n");
        
    } while (check == 1);

    do {
        printf("Enter movie end time [HH:MM]: ");
        scanf("%s", end); getchar();

        check = 0; // startA:startB , endA:endB
        
        if (strlen(end) != 5) check = 1;
        if (end[2] != ':') check = 1;
        if (!isdigit(end[0]) || !isdigit(end[1])) check = 1;
        if (!isdigit(end[3]) || !isdigit(end[4])) check = 1;
        
        movies[movieCount].endA = (end[0] - 48) * 10;
        movies[movieCount].endA += (end[1] - 48);
        
        movies[movieCount].endB = (end[3] - 48) * 10;
        movies[movieCount].endB += (end[4] - 48);

        if (movies[movieCount].endA < 0 || movies[movieCount].endA > 23) check = 1;
        if (movies[movieCount].endB < 0 || movies[movieCount].endB > 59) check = 1;
        
        if (movies[movieCount].endA < movies[movieCount].startA) {
            check = 1;
        } else if (movies[movieCount].endA == movies[movieCount].startA) {
            if (movies[movieCount].endB < movies[movieCount].startB) {
                check = 1;
            } else if (movies[movieCount].endB == movies[movieCount].startB) check = 1;
        }
        if (check == 1) printf("Invalid Time Format!\n");
        
    } while (check == 1);

    do {
        printf("Enter movie studio [1 - 10]: ");
        scanf("%d", &movies[movieCount].studio); getchar();
        if (movies[movieCount].studio < 1 || movies[movieCount].studio > 10) {
            printf("Movie studio must be between 1-10!");
        }
    } while (movies[movieCount].studio < 1 || movies[movieCount].studio > 10);

    movies[movieCount].dur = movies[movieCount].endA - movies[movieCount].startA;
    movies[movieCount].dur *= 60;
    
    if (movies[movieCount].endB == 0) {
        if (movies[movieCount].startB == 0) {
            movies[movieCount].dur += 60 - movies[movieCount].startB;
            movies[movieCount].dur -= 60;
        } else {
            movies[movieCount].dur += 60 - movies[movieCount].startB;
            movies[movieCount].dur -= 60;
        }
    }
    else movies[movieCount].dur += movies[movieCount].endB - movies[movieCount].startB;

    sprintf(movies[movieCount].id, "MV%d%d%d", rand() % 10, rand() % 10, rand() % 10);
    
    puts("Movie added successfully!");

    movieCount++;
}

void updateMenu()
{
    system("cls");
    
    if (movieCount == 0) {
        printf("No movie to update :("); return;
    } else {
        viewAll();
        
        int pick;
        do {
            printf("Enter movie index to update [1-%d]: ", movieCount);
            scanf("%d", &pick); getchar();
        } while (pick < 1 || pick > movieCount);
        
        pick--;

        int check;

        do {
            printf("Enter movie name [1 - 20 chars]: ");
            scanf("%[^\n]", movies[pick].name); getchar();
            if (strlen(movies[pick].name) < 1 || strlen(movies[pick].name) > 20) {
                printf("Movie name must be between 1-20 characters!"); getchar();
            }
        } while (strlen(movies[pick].name) < 1 || strlen(movies[pick].name) > 20);
        
        //
        do {
            printf("Enter movie start time [HH:MM]: ");
            scanf("%s", start); getchar();

            check = 0;

            if (strlen(start) != 5) check = 1;
            if (start[2] != ':') check = 1;
            if (!isdigit(start[0]) || !isdigit(start[1])) check = 1;
            if (!isdigit(start[3]) || !isdigit(start[4])) check = 1;

            movies[pick].startA = (start[0] - 48) * 10;
            movies[pick].startA += (start[1] - 48);
            
            movies[pick].startB = (start[3] - 48) * 10;
            movies[pick].startB += (start[4] - 48);

            if (movies[pick].startA < 0 || movies[pick].startA > 23) check = 1;
            if (movies[pick].startB < 0 || movies[pick].startB > 59) check = 1;
            if (movies[pick].startA == 23 && movies[pick].startB == 59) check = 1;
            
            if (check == 1) printf("Invalid Time Format!\n");
            
        } while (check == 1);

        do {
            printf("Enter movie end time [HH:MM]: ");
            scanf("%s", end); getchar();

            check = 0; // startA:startB , endA:endB
            
            if (strlen(end) != 5) check = 1;
            if (end[2] != ':') check = 1;
            if (!isdigit(end[0]) || !isdigit(end[1])) check = 1;
            if (!isdigit(end[3]) || !isdigit(end[4])) check = 1;
            
            movies[pick].endA = (end[0] - 48) * 10;
            movies[pick].endA += (end[1] - 48);
            
            movies[pick].endB = (end[3] - 48) * 10;
            movies[pick].endB += (end[4] - 48);

            if (movies[pick].endA < 0 || movies[pick].endA > 23) check = 1;
            if (movies[pick].endB < 0 || movies[pick].endB > 59) check = 1;
            
            if (movies[pick].endA < movies[pick].startA) {
                check = 1;
            } else if (movies[pick].endA == movies[pick].startA) {
                if (movies[pick].endB < movies[pick].startB) {
                    check = 1;
                } else if (movies[pick].endB == movies[pick].startB) check = 1;
            }
            if (check == 1) printf("Invalid Time Format!\n");
            
        } while (check == 1);

        do {
            printf("Enter movie studio [1 - 10]: ");
            scanf("%d", &movies[pick].studio); getchar();
            if (movies[pick].studio < 1 || movies[pick].studio > 10) {
                printf("Movie studio must be between 1-10!"); getchar();
            }
        } while (movies[pick].studio < 1 || movies[pick].studio > 10);

        movies[pick].dur = movies[pick].endA - movies[pick].startA;
        movies[pick].dur *= 60;
        
        if (movies[pick].endB == 0) {
            if (movies[pick].startB == 0) {
                movies[pick].dur += 60 - movies[pick].startB;
                movies[pick].dur -= 60;
            } else {
                movies[pick].dur += 60 - movies[pick].startB;
                movies[pick].dur -= 60;
            }
        }
        else movies[pick].dur += movies[pick].endB - movies[pick].startB;
        
        puts("Movie updated!");
    }
}

void deleteMenu()
{
    system("cls");
    
    if (movieCount == 0) {
        puts("No movie to delete :(");
    } else {
        viewAll();

        int pick;
        do {
            printf("Choose index to delete [1-%d]: ", movieCount);
            scanf("%d", &pick); getchar();
        } while (pick < 1 || pick > movieCount);
        
        pick--;

        for (int i = pick; i < movieCount - pick + 2; i++) {
            movies[i] = movies[i + 1];
        }
        
        movieCount--;
        
        printf("Movie has been deleted!\n");
    }
}

void exportData()
{
    FILE* file = fopen("cinema.csv", "w");

    for (int i = 0; i < movieCount; i++) {
        fprintf(file, "%s,%s,%02d:%02d,%02d:%02d,%d\n", movies[i].id, movies[i].name, movies[i].startA, movies[i].startB, movies[i].endA, movies[i].endB, movies[i].studio);
    }
   
    fclose(file);
}

int main()
{
    int input;
    
    srand(time(0));
    importData();
    
    do {
        displayHeader();
        printf("Input [1 - 5]: "); scanf("%d", &input); getchar();

        switch (input) {
            case 1:
                viewAll();
                printf("Press enter to continue......"); getchar();
                break;
            case 2:
                addMenu();
                printf("Press enter to continue..."); getchar();
                break;
            case 3:
                updateMenu();
                printf("Press enter to continue..."); getchar();
                break;
            case 4:
                deleteMenu();
                printf("Press enter to continue..."); getchar();
                break;
            case 5:
                exportData();
                printf("Thanks for using this app!");
                break;
            default:
                puts("Please input a valid number!");
                printf("Press enter to continue..."); getchar();
        }
        
    } while (input != 5);
}

/*

| 1   | MV101    |                  Aquaman |    14:25    |    15:30    |       65 Minutes     |      8 |
| 2   | MV127    |         The Hunger Games |    10:45    |    11:50    |       65 Minutes     |      5 |
| 3   | MV561    |                  Minions |    15:45    |    17:00    |       75 Minutes     |      7 |
| 4   | MV041    |        Violet Evergarden |    19:00    |    20:30    |       90 Minutes     |      3 |
| 5   | MV222    |               Evangelion |    11:20    |    13:05    |      105 Minutes     |      4 |
| 6   | MV174    |               Squid Game |    20:30    |    23:00    |      150 Minutes     |      3 |
| 7   | MV014    |     Diet Journey of Josh |    09:00    |    18:00    |      540 Minutes     |      1 |

*/