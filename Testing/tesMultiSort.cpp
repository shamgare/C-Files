#include <stdio.h>
#include <string.h>

struct karyawan {
    char role[200];
    double ipk;
    char nama[200];
    char jurusan[200];
    int id;
} karyawan[2000];

void swap(int a, int b)
{
    struct karyawan temp = karyawan[a];
    karyawan[a] = karyawan[b];
    karyawan[b] = temp;
}

int part(int low, int high)
{
    int i = low - 1;
    int j = low;
    char pivot[200];
    strcpy(pivot, karyawan[high].jurusan);
    char pivot3[200];
    strcpy(pivot, karyawan[high].role);
    double pivot2 = karyawan[high].ipk;

    while (j < high) {
        if (strcmp(pivot, karyawan[j].jurusan) > 0) {
            i++;
            swap(i, j);
        }
        else if (karyawan[j].ipk < pivot2 && strcmp(pivot3, karyawan[j].role) == 0) {
            i++;
            swap(i, j);
        }
        // else if (strcmp(pivot, karyawan[j].jurusan) == 0 && karyawan[j].ipk < pivot2 && strcmp(pivot3, karyawan[j].role) == 0) {
        //     i++;
        //     swap(i, j);   
        // }
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

int main()
{
    FILE* file = fopen("karyawan.txt", "r");

    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%d#%[^#]#%[^#]#%lf#%[^\n]\n", &karyawan[i].id, karyawan[i].nama, karyawan[i].jurusan, &karyawan[i].ipk, karyawan[i].role);
        i++;
    }

    qs(0, i - 1);

    for (int j = 0; j < i; j++) {
        printf("%d %s %s %.2lf %s\n", karyawan[j].id, karyawan[j].nama, karyawan[j].jurusan, karyawan[j].ipk, karyawan[j].role);
    }
}
