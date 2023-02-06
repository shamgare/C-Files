#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song {
    char title[100];
    char artist[100];
    int duration;
};
struct playlist {
    char name[100];
    struct song song[20]; // tiap playlist bisa 20 song
    int songCount;
};
struct playlist pl[100]; // bisa bikin 100 playlist

int plCount = 0;






int search(char* playlistName)
{
    if (plCount == 0) return -1; // belom ada playlist

    int left = 0;
    int right = plCount - 1;

    while (left <= right) { // usahain <= aja
        int mid = (left + right) / 2;
        if (strcmp(playlistName, pl[mid].name) == 0) {
            return mid;
        } else if (strcmp(playlistName, pl[mid].name) < 0)  { // jadi parameter duluan, terus lambangnya ke kiri, rumusnya right mid - 1
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // ga ketemu playlistnya
}

void swapPl(int a, int b)
{
    struct playlist temp = pl[a];
    pl[a] = pl[b];
    pl[b] = temp;
}

void swapSong(int a, int b, int index)
{
    struct song temp = pl[index].song[a];
    pl[index].song[a] = pl[index].song[b];
    pl[index].song[b] = temp;
}

int partitionPl(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[200];
    strcpy(pivot, pl[high].name);

    while (j < high) {
        if (strcmp(pivot, pl[j].name) > 0) {
            i++;
            swapPl(i, j);
        }
        j++;
    }
    swapPl(high, i+1);

    return i+1;
}

int partitionSong(int low, int high, int index)
{
    int i = low - 1;
    int j = low;
    char pivot[200];
    strcpy(pivot, pl[index].song[high].title);

    while (j < high) {
        if (strcmp(pivot, pl[index].song[j].title) > 0) {
            i++;
            swapSong(i, j, index);
        }
        j++;
    }
    swapSong(high, i+1, index);

    return i+1;
}

void quickSortPl(int low, int high)
{
    if (low < high) {
        int pos = partitionPl(low, high);

        quickSortPl(low, pos-1);
        quickSortPl(pos+1, high);
    }
}

void quickSortSong(int low, int high, int index)
{
    if (low < high) {
        int pos = partitionSong(low, high, index);

        quickSortSong(low, pos-1, index);
        quickSortSong(pos+1, high, index);
    }
}

void importData()
{
    FILE* file = fopen("songs.txt", "r");

    char title[100];
    char artist[100];
    int duration;
    char playlistName[100];
    
    if (file == NULL) return;
    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%d#%[^\n]\n", title, artist, &duration, playlistName);

        int searchIndex = search(playlistName);

        if (searchIndex == -1) {
            struct playlist newPl;
            strcpy(newPl.name, playlistName); //playlist name
            newPl.songCount = 0; //song count dalam playlist

            struct song newSong;
            strcpy(newSong.title, title); //song title
            strcpy(newSong.artist, artist); //song artist
            newSong.duration = duration; //song duration

            newPl.song[newPl.songCount] = newSong; //masukkin data song baru ke dalam playlist
            newPl.songCount++;

            pl[plCount] = newPl; //masukkin playlist yg baru di scan ke dalam list playlist
            plCount++;
        } else {
            strcpy(pl[searchIndex].song[pl[searchIndex].songCount].title, title);
            strcpy(pl[searchIndex].song[pl[searchIndex].songCount].artist, artist);
            pl[searchIndex].song[pl[searchIndex].songCount].duration = duration;
            pl[searchIndex].songCount++;
        }
    }

    fclose(file);
}

void viewAll()
{
    quickSortPl(0, plCount - 1);

    for (int i = 0; i < plCount; i++) {
        quickSortSong(0, pl[i].songCount - 1, i);
    }

    for (int i = 0; i < plCount; i++) {
        printf("Playlist: %s\n", pl[i].name);
        for (int j = 0; j < pl[i].songCount; j++) {
            printf("\t%s - %s - %ds\n", pl[i].song[j].title, pl[i].song[j].artist, pl[i].song[j].duration);
        }
    }
}

void addMenu()
{
    char title[255] = {}, artist[255] = {}, playlistName[255] = {};
    int duration = 0;
    
    do {
        printf("Please input a title name [not empty]: ");
        scanf("%[^\n]", title);
        getchar();
    } while (strcmp(title, "") == 0);
    do {
        printf("Please input a title artist [not empty]: ");
        scanf("%[^\n]", artist);                
        getchar();
    } while (strcmp(artist, "") == 0);
    do {
        printf("Please input a title duration [in seconds]: ");
        scanf("%d", &duration);
        getchar();
    } while (duration <= 0);
    do {
        printf("Please input playlist name [not empty]: ");
        scanf("%[^\n]", playlistName);
        getchar();
    } while (strcmp(playlistName, "") == 0);

    int searchIndex = search(playlistName);

    if (searchIndex == -1) {
        struct playlist newPl;
        strcpy(newPl.name, playlistName); //playlist name
        newPl.songCount = 0; //song count dalam playlist

        struct song newSong;
        strcpy(newSong.title, title); //song title
        strcpy(newSong.artist, artist); //song artist
        newSong.duration = duration; //song duration

        newPl.song[newPl.songCount] = newSong; //masukkin data song baru ke dalam playlist
        newPl.songCount++;

        pl[plCount] = newPl; //masukkin playlist yg baru di scan ke dalam list playlist
        plCount++;
    } else {
        strcpy(pl[searchIndex].song[pl[searchIndex].songCount].title, title);
        strcpy(pl[searchIndex].song[pl[searchIndex].songCount].artist, artist);
        pl[searchIndex].song[pl[searchIndex].songCount].duration = duration;
        pl[searchIndex].songCount++;
    }

    quickSortPl(0, plCount - 1);

    for (int i = 0; i < plCount; i++) {
        quickSortSong(0, pl[i].songCount - 1, i);
    }
}

void searchMenu()
{
    char check[100];
    do {
        printf("Song to search: ");
        scanf("%[^\n]", check); getchar();
    } while (strcmp(check, "") == 0);
    
    for (int i = 0; i < plCount; i++) {
        int x = 0;
        for (int j = 0; j < pl[i].songCount; j++) {
            char temp[200] = {};
            strcpy(temp, pl[i].song[j].title);
            if (strstr(strlwr(temp), strlwr(check)) != NULL) {
                if (x++ == 0) printf("%s\n", pl[i].name);
                printf("\t%s - %s - %d\n", pl[i].song[j].title, pl[i].song[j].artist, pl[i].song[j].duration);
            }
        }
    }
}

void exportData()
{
    FILE* file = fopen("songs.txt", "w");

    for (int i = 0; i < plCount; i++) {
        for (int j = 0; j < pl[i].songCount; j++) {
            fprintf(file, "%s#%s#%d#%s\n", pl[i].song[j].title, pl[i].song[j].artist, pl[i].song[j].duration, pl[i].name);
        }
    }

    fclose(file);
}

int main()
{
    importData();

    int input;
    do {
        puts("Song Player");
        puts("=================");
        puts("1. Add New Song");
        puts("2. Show All Songs");
        puts("3. Search Song(s)");
        puts("4. Exit");
        printf("Choose >> "); scanf("%d", &input); getchar();

        if (input == 1) {
            addMenu();
            puts("Added...");
            printf("Press any key to continue....");
            getchar();
        } else if (input == 2) {
            if (plCount == 0) {
                puts("Empty...");
                printf("Press any key to continue....");
                getchar();
            } else {
                viewAll();
                printf("Press any key to continue....");
                getchar();
            }
        } else if (input == 3) {
            if (plCount == 0) {
                puts("Empty...");
                printf("Press any key to continue....");
                getchar();
            } else {
                searchMenu();
                printf("Press any key to continue....");
                getchar();
            }
        } else if (input == 4) {
            exportData();
            puts("Thanks for using this app!");
        } else {
            puts("Please input a valid number.");
            getchar();
        }

    } while (input != 4);

    return 0;
}