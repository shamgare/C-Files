#include <stdio.h>

int main()
{
    int dosen;
    scanf("%d", &dosen);
    getchar();

    char kodeD[dosen][101] = {};
    char namaD[dosen][101] = {};
    char kelD[dosen][101] = {};

    int sisD[dosen] = {};

    char kodeM[dosen][101][50] = {};
    char namaM[dosen][101][50] = {};
    char kelM[dosen][101][50] = {};

    char ayah[dosen][101][50] = {};
    char ibu[dosen][101][50] = {};
    int sibling[dosen][101] = {};

    int i = 0;
    int index;

    for (int i = 0; i < dosen; i++) {
        scanf("%s %s %s", kodeD[i], namaD[i], kelD[i]);
        getchar();
        scanf("%d", &sisD[i]);
        getchar();
        
        for (int j = 0; j < sisD[i]; j++) {
            scanf("%s %s %s %s %s", kodeM[i][j], namaM[i][j], kelM[i][j], ayah[i][j], ibu[i][j]);
            getchar();
            scanf("%d", &sibling[i][j]);
            getchar();
        }
        scanf("%d", &index);
    }

    printf("Kode Dosen: %s\n", kodeD[index-1]);
    printf("Nama Dosen: %s\n", namaD[index-1]);
    printf("Gender Dosen: %s\n", kelD[index-1]);
    printf("Jumlah Mahasiswa: %d\n", sisD[index-1]);

    for (int j = 0; j < sisD[index-1]; j++) {
        printf("Kode Mahasiswa: %s\n", kodeM[index-1][j]);
        printf("Nama Mahasiswa: %s\n", namaM[index-1][j]);
        printf("Gender Mahasiswa: %s\n", kelM[index-1][j]);
        printf("Nama Ayah: %s\n", ayah[index-1][j]);
        printf("Nama Ibu: %s\n", ibu[index-1][j]);
        printf("Jumlah Saudara Kandung: %d\n", sibling[index-1][j]);
    }

    return 0;
}