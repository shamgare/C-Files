#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song {
	char title[100];
	char artist[100];
	int duration;
};

struct playlist {
	char plName[100];
	int songCount = 0;
	struct song song[20];
};

struct playlist playlist[50];

int plCount = 0;

int searchPl(char* plName)
{
	int left = 0;
	int right = plCount - 1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (strcmp(plName, playlist[mid].plName) == 0) {
			return mid;
		} else if (strcmp(plName, playlist[mid].plName) < 0) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

void swapPl(int a, int b)
{
	struct playlist temp = playlist[a];
	playlist[a] = playlist[b];
	playlist[b] = temp;	
}

int partPl(int low, int high)
{
	int i = low - 1;
	int j = low;
	char pivot[200];
	strcpy(pivot, playlist[high].plName);

	while (j < high) {
		if (strcmp(pivot, playlist[j].plName) > 0) {
			i++;
			swapPl(i, j);
		}
		j++;
	}
	swapPl(i+1, high);

	return i+1;
}

void qsPl(int low, int high)
{
	if (low < high) {
		int pos = partPl(low, high);

		qsPl(low, pos - 1);
		qsPl(pos + 1, high);
	}
}

void swapSong(int a, int b, int index)
{
	struct song temp = playlist[index].song[a];
	playlist[index].song[a] = playlist[index].song[b];
	playlist[index].song[b] = temp;
}

int partSong(int low, int high, int index)
{
	int i = low - 1;
	int j = low;
	char pivot[200];
	strcpy(pivot, playlist[index].song[high].title);

	while (j < high) {
		if (strcmp(pivot, playlist[index].song[j].title) > 0) {
			i++;
			swapSong(i, j, index);
		}
		j++;
	}
	swapSong(i+1, high, index);

	return i+1;
}

void qsSong(int low, int high, int index)
{
	if (low < high) {
		int pos = partSong(low, high, index);

		qsSong(low, pos - 1, index);
		qsSong(pos + 1, high, index);
	}
}

void importData()
{
	FILE* file = fopen("songs.txt", "r");
	if (file == NULL) return;
	
	char title[100];
	char artist[100];
	int duration;
	char plName[100];
	
	while (!feof(file)) {
		fscanf(file, "%[^#]#%[^#]#%d#%[^\n]\n", title, artist, &duration, plName);
		
		int searchIndex = searchPl(plName);
		
		if (searchIndex == -1) {
			struct playlist newPl;
			strcpy(newPl.plName, plName);
			newPl.songCount = 0;

			struct song newSong;
			strcpy(newSong.artist, artist);
			strcpy(newSong.title, title);
			newSong.duration = duration;
			
			newPl.song[newPl.songCount] = newSong;
			newPl.songCount++;

			playlist[plCount] = newPl;
			plCount++;
		} else {
			strcpy(playlist[searchIndex].song[playlist[searchIndex].songCount].artist, artist);
			strcpy(playlist[searchIndex].song[playlist[searchIndex].songCount].title, title);
			playlist[searchIndex].song[playlist[searchIndex].songCount].duration = duration;
			playlist[searchIndex].songCount++;
		}
	}

	fclose(file);
}

void addMenu()
{
	char title[100];
	char artist[100];
	int duration;
	char plName[100];
	
	printf("Input title: ");
	scanf("%[^\n]", title); getchar();
	printf("Input artist: ");
	scanf("%[^\n]", artist); getchar();
	printf("Input duration: ");
	scanf("%d", &duration); getchar();
	printf("Input playlist name: ");
	scanf("%[^\n]", plName); getchar();
	
	int searchIndex = searchPl(plName);
	
	if (searchIndex == -1) {
		struct playlist newPl;
		strcpy(newPl.plName, plName);
		newPl.songCount = 0;

		struct song newSong;
		strcpy(newSong.artist, artist);
		strcpy(newSong.title, title);
		newSong.duration = duration;
			
		newPl.song[newPl.songCount] = newSong;
		newPl.songCount++;

		playlist[plCount] = newPl;
		plCount++;
	} else {
		strcpy(playlist[searchIndex].song[playlist[searchIndex].songCount].artist, artist);
		strcpy(playlist[searchIndex].song[playlist[searchIndex].songCount].title, title);
		playlist[searchIndex].song[playlist[searchIndex].songCount].duration = duration;
		playlist[searchIndex].songCount++;
	}
	
	qsPl(0, plCount - 1);
	
	for (int i = 0; i < plCount; i++) {
		qsSong(0, playlist[i].songCount - 1, i);
	}
}

void viewAll()
{
	printf("%d\n", plCount);
	for (int i = 0; i < plCount; i++) {
		printf("%s\n", playlist[i].plName);
		for (int j = 0; j < playlist[i].songCount; j++) {
			printf("\t%s - %s - %d\n", playlist[i].song[j].title, playlist[i].song[j].artist, playlist[i].song[j].duration);
		}
	}
}

void searchMenu()
{
	char check[200];

	printf("Input song to search: ");
	scanf("%s", check); getchar();

	for (int i = 0; i < plCount; i++) {
		int x = 0;
		for (int j = 0; j < playlist[i].songCount; j++) {
			if (strstr(playlist[i].song[j].title, check) != NULL) {
				if (x++ == 0) printf("%s\n", playlist[i].plName);
				printf("\t%s - %s - %ds\n", playlist[i].song[j].title, playlist[i].song[j].artist, playlist[i].song[j].duration);
			}
		}
	}
}

void exportData()
{
	FILE* file = fopen("songs.txt", "w");

	for (int i = 0; i < plCount; i++) {
		for (int j = 0; j < playlist[i].songCount; j++) {
			fprintf(file, "%s#%s#%d#%s\n", playlist[i].song[j].title, playlist[i].song[j].artist, playlist[i].song[j].duration, playlist[i].plName);
		}
	}

	fclose(file);
}

int main()
{
	int input = 0;
	importData();
	
	do {
		puts("Song Player");
		puts("=================");
		puts("1. Add song");
		puts("2. View song(s)");
		puts("3. Search song");
		puts("4. Exit");
		printf("Choose >> "); scanf("%d", &input); getchar();
		
		if (input == 1) {
			addMenu();
			printf("Press any key to continue...."); getchar();
		} else if (input == 2) {
			viewAll();
			printf("Press any key to continue...."); getchar();
		} else if (input == 3) {
			searchMenu();
			printf("Press any key to continue...."); getchar();
		} else if (input == 4) {
			exportData();
			printf("Thanks for using this app!");
		} else {
			puts("Please input a valid number!");
			printf("Press any key to continue...."); getchar();
		}
	} while (input != 4);
}