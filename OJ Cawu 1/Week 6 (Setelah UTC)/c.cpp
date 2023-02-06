#include <stdio.h>

struct dosen {
    char kodeD[101][101] = {};
    char namaD[101][101] = {};
    char kelD[101][101] = {};
    int sisD[101] = {};
};

struct siswa {
    char kodeM[101][101] = {};
    char namaM[101][101] = {};
    char kelM[101][101] = {};
};

struct kel {
    char ayah[101][101] = {};
    char ibu[101][101] = {};
    int sibling[101] = {};
};

int main()
{
    struct dosen d1;
    struct siswa s1;
    struct kel k1;

    int dosen;
    int siswaSebelum = 0;
    scanf("%d", &dosen);

    int i = 0;
    int index;

    for (int i = 0; i < dosen; i++) {
        scanf("%s %s %s", d1.kodeD[i], d1.namaD[i], d1.kelD[i]);
        getchar();
        scanf("%d", &d1.sisD[i]);
        getchar();
        
        for (int j = 0; j < d1.sisD[i]; j++) {
            scanf("%s %s %s %s %s", s1.kodeM[j], s1.namaM[j], s1.kelM[j], k1.ayah[j], k1.ibu[j]);
            getchar();
            scanf("%d", &k1.sibling[j]);
            getchar();
        }
        scanf("%d", &index);
    }

    for (int k = index-2; k >= 0; k--) {
        siswaSebelum += d1.sisD[k];
    }

    // printf("%d", siswaSebelum);
    printf("Kode Dosen: %s\n", d1.kodeD[index-1]);
    printf("Nama Dosen: %s\n", d1.namaD[index-1]);
    printf("Gender Dosen: %s\n", d1.kelD[index-1]);
    printf("Jumlah Mahasiswa: %d\n", d1.sisD[index-1]);

    for (int j = 0; j < d1.sisD[index-1]; j++) {
        printf("Kode Mahasiswa: %s\n", s1.kodeM[j+siswaSebelum]);
        printf("Nama Mahasiswa: %s\n", s1.namaM[j+siswaSebelum]);
        printf("Gender Mahasiswa: %s\n", s1.kelM[j+siswaSebelum]);
        printf("Nama Ayah: %s\n", k1.ayah[j+siswaSebelum]);
        printf("Nama Ibu: %s\n", k1.ibu[j+siswaSebelum]);
        printf("Jumlah Saudara Kandung: %d\n", k1.sibling[j+siswaSebelum]);
    }

    return 0;
}