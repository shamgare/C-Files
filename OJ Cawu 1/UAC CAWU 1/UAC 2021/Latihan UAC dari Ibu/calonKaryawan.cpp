#include <stdio.h>

struct calon {
    char id[20];
    char nama[200];
    char jurusan[200];
    double ipk;
    char posisi[200];
} calon[2000];

int main()
{
    int karyawan; scanf("%d", &karyawan);

    for (int i = 0; i < karyawan; i++) {
        scanf("%s %s %s %lf %s", calon[i].id, calon[i].nama, calon[i].jurusan, &calon[i].ipk, calon[i].posisi);
        getchar();
    }

}