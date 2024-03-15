#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct mahasiswa
{
    int NIM;
    char nama[50];
    int uas;
    int uts;
    int nilai;
    int rata_rata;
    bool status;
}mahasiswa_t;

mahasiswa_t create_mahasiswa(){

    mahasiswa_t mahasiswa;

    printf("Masukkan NIM: ");
    scanf("%d", &mahasiswa.NIM);
    printf("Masukkan Nama: ");
    getchar();
    fgets(mahasiswa.nama, sizeof(mahasiswa.nama), stdin);
    mahasiswa.nama[strcspn(mahasiswa.nama, "\r\n")] = 0;
    printf("Masukkan Nilai UAS: ");
    scanf("%d", &mahasiswa.uas);
    printf("Masukkan Nilai UTS: ");
    scanf("%d", &mahasiswa.uts);

    mahasiswa.nilai = mahasiswa.uas + mahasiswa.uts;
    
    mahasiswa.rata_rata = (mahasiswa.nilai / 2);

    if (mahasiswa.rata_rata >= 60)
    {
        mahasiswa.status = true;
    }
    else
    {
        mahasiswa.status = false;
    }

    return mahasiswa;
}

void print_mahasiswa(mahasiswa_t *mahasiswa){
    printf("\n\n");
    printf("NIM: %d \n", mahasiswa->NIM);
    printf("Nama: %s \n", mahasiswa->nama);
    printf("UAS: %d \n", mahasiswa->uas);
    printf("UTS: %d \n", mahasiswa->uts);
    printf("Nilai: %d \n", mahasiswa->nilai);
    printf("Rata-Rata: %d \n", mahasiswa->rata_rata);

    if (mahasiswa->status)
    {
        printf("Status: LULUS");
    }
    else
    {
        printf("Status: GAGAL");
    }
    
    
}

void print_hasil(mahasiswa_t *mahasiswa, int x){

    mahasiswa_t *temp = mahasiswa;
    printf("\nHasil: \n");
    for (int i = 0; i < x; i++)
    {
        if (temp->status)
        {
            printf("%s LULUS \n", temp[i].nama);
        }
        else
        {
            printf("%s GAGAL \n", temp[i].nama);
        }
        
    }
    
}

int main(void){
    system("cls");
    int x;
    printf("Masukkan Jumlah Mahasiswa: ");
    scanf("%d", &x);

    mahasiswa_t *array_mahasiswa = malloc(sizeof(mahasiswa_t) * x);

    for (int i = 0; i < x; i++)
    {
        array_mahasiswa[i] = create_mahasiswa();
    }

    print_hasil(array_mahasiswa, x);

    // print_mahasiswa(mahasiswa);
}
