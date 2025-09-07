#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// struct mahasiswa
typedef struct mahasiswa
{
    char no_peserta[50];
    char nama[50];
    int teori;
    int praktek;
    int nilai;
    int rata_rata;
    bool status;
}mahasiswa_t;

// struct array mahasiswa
typedef struct array
{
    mahasiswa_t *data;
    int total_data;
}array_t;


// utilities function definition
mahasiswa_t create_mahasiswa();
array_t *create_array(int len);
void print_mahasiswa(array_t *mahasiswa);

// main function
int main(void){
    system("cls");
    int len;
    printf("Masukkan Jumlah Mahasiswa: ");
    scanf("%d", &len);

    array_t *array = create_array(len);

    print_mahasiswa(array);
}

// create mahasiswa function
mahasiswa_t create_mahasiswa(){

    mahasiswa_t mahasiswa;

    getchar();
    printf("Masukkan Nomor Peserta: ");
    fgets(mahasiswa.no_peserta, sizeof(mahasiswa.no_peserta), stdin);
    mahasiswa.no_peserta[strcspn(mahasiswa.no_peserta, "\r\n")] = 0;

    printf("Masukkan Nama: ");
    fgets(mahasiswa.nama, sizeof(mahasiswa.nama), stdin);
    mahasiswa.nama[strcspn(mahasiswa.nama, "\r\n")] = 0;

    printf("Masukkan Nilai Teori: ");
    scanf("%d", &mahasiswa.teori);

    printf("Masukkan Nilai Praktek: ");
    scanf("%d", &mahasiswa.praktek);

    mahasiswa.nilai = mahasiswa.teori + mahasiswa.praktek;
    
    mahasiswa.rata_rata = (mahasiswa.nilai / 2);

    if (mahasiswa.rata_rata >= 60)
    {
        mahasiswa.status = true;
    }
    else
    {
        mahasiswa.status = false;
    }

    printf("\n");

    return mahasiswa;
}

// create array mahasiswa function
array_t *create_array(int len){
    array_t *temp = malloc(sizeof(array_t));
    temp->total_data = len;
    temp->data = calloc(len, sizeof(mahasiswa_t));

    for (int i = 0; i < temp->total_data; i++)
    {
        temp->data[i] = create_mahasiswa();
    }
    
    return temp;
}

// print mahasiswa function
void print_mahasiswa(array_t *mahasiswa){
    system("cls");
    for (int i = 0; i < mahasiswa->total_data; i++)
    {
        printf("Nomor Peserta: %s \n", mahasiswa->data[i].no_peserta);
        printf("Nama: %s \n", mahasiswa->data[i].nama);
        printf("Nilai Teori: %d \n", mahasiswa->data[i].teori);
        printf("Nilai Praktek: %d \n", mahasiswa->data[i].praktek);
        printf("Nilai: %d \n", mahasiswa->data[i].nilai);
        printf("Rata-Rata: %d \n", mahasiswa->data[i].rata_rata);

        if (mahasiswa->data[i].status)
        {
            printf("Status: LULUS\n");
        }
        else
        {
            printf("Status: GAGAL\n");
        }

        printf("\n");
    }
    
}
