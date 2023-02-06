#include <stdio.h>

struct first {
    char name[150] = {};
    long long int nim;
    int age;
    long long int post;
    char plc[150] = {};
    char date[150] = {};
    char sch[150] = {};
    int sib;
    int height;
    long long int bank;
};

int main()
{
    struct first f1;
    int kasus;
    scanf("%d", &kasus);

    for (int i = 0; i < kasus; i++) {
        scanf("%s", f1.name);
        scanf("%lld", &f1.nim);
        scanf("%d", &f1.age);
        scanf("%lld", &f1.post);
        getchar();
        scanf("%s", f1.plc);
        scanf("%s", f1.date);
        getchar();
        scanf("%[^\n]", f1.sch);
        getchar();
        scanf("%d", &f1.sib);
        scanf("%d", &f1.height);
        scanf("%lld", &f1.bank);

        printf("Mahasiswa ke-%d:\n", i+1);
        printf("Nama: %s\n", f1.name);
        printf("NIM: %lld\n", f1.nim);
        printf("Umur: %d\n", f1.age);
        printf("Kode Pos: %lld\n", f1.post);
        printf("Tempat Lahir: %s\n", f1.plc);
        printf("Tanggal Lahir: %s\n", f1.date);
        printf("Almamater SMA: %s\n", f1.sch);
        printf("Jumlah Saudara Kandung: %d\n", f1.sib);
        printf("Tinggi Badan: %d\n", f1.height);
        printf("NOMOR REKENING: %lld\n", f1.bank);
    }
    
    return 0;
}