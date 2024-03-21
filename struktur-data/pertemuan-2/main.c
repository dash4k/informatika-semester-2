#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pasien
{
    char nama[50];
    int berat;
    int tinggi;
}pasien_t;

typedef struct array
{
    int jumlah_pasien;
    pasien_t *array_pasien;
}array_t;


array_t *create_array(int jumlah){
    array_t *array = malloc(sizeof(array_t));
    array->jumlah_pasien = jumlah;
    array->array_pasien = calloc(array->jumlah_pasien, sizeof(pasien_t));
}

pasien_t input_pasien(){
    pasien_t pasien;

    printf("Masukkan nama pasien: ");
    getchar();
    fgets(pasien.nama, sizeof(pasien.nama), stdin);
    pasien.nama[strcspn(pasien.nama, "\r\n")] = 0;

    printf("Masukkan berat pasien: ");
    scanf("%d", &pasien.berat);

    printf("Masukkan tinggi pasien: ");
    scanf("%d", &pasien.tinggi);

    return pasien;
}

int berat_terendah(array_t *array_pasien){
    int index = 0;
    int terendah = array_pasien->array_pasien[0].berat;
    for (int i = 1; i < array_pasien->jumlah_pasien; i++)
    {
        if (array_pasien->array_pasien[i].berat < terendah)
        {
            terendah = array_pasien->array_pasien[i].berat;
            index = i;
        }
        
    }
    return index;
}

int berat_rerata(array_t *array_pasien){
    int berat_rerata = 0;
    for (int i = 0; i < array_pasien->jumlah_pasien; i++)
    {
        berat_rerata += array_pasien->array_pasien[i].berat;
    }
    return berat_rerata / array_pasien->jumlah_pasien;
}

int tinggi_terendah(array_t *array_pasien){
    int index = 0;
    int terendah = array_pasien->array_pasien[0].tinggi;
    for (int i = 1; i < array_pasien->jumlah_pasien; i++)
    {
        if (array_pasien->array_pasien[i].tinggi < terendah)
        {
            terendah = array_pasien->array_pasien[i].tinggi;
            index = i;
        }
        
    }
    return index;
}

int tinggi_rerata(array_t *array_pasien){
    int tinggi_rerata = 0;
    for (int i = 0; i < array_pasien->jumlah_pasien; i++)
    {
        tinggi_rerata += array_pasien->array_pasien[i].tinggi;
    }
    return tinggi_rerata / array_pasien->jumlah_pasien;
}

void print_array(array_t *array_pasien){
    system("cls");
    printf("Pasien: \n");
    for (int i = 0; i < array_pasien->jumlah_pasien; i++)
    {
        printf("Nama Pasien: %s\n", array_pasien->array_pasien[i].nama);
        printf("Tinggi Pasien: %d\n", array_pasien->array_pasien[i].tinggi);
        printf("Berat Pasien: %d\n", array_pasien->array_pasien[i].berat);
        printf("\n");
    }
}

void print_lainnya(array_t *array_pasien, int index_tinggi, int index_berat){
    printf("Berat Rata-Rata: %d\n", berat_rerata(array_pasien));
    printf("Tinggi Rata-Rata: %d\n", tinggi_rerata(array_pasien));
    printf("\n");
    printf("Berat terendah: %s dengan berat %d Ton\n", array_pasien->array_pasien[index_berat].nama, array_pasien->array_pasien[index_berat].berat);
    printf("Tinggi terendah: %s dengan tinggi %d Meter\n", array_pasien->array_pasien[index_tinggi].nama, array_pasien->array_pasien[index_tinggi].tinggi);
}

int main(void){
    system("cls");
    int len;
    printf("Masukkan jumlah pasien: ");
    scanf("%d", &len);
    array_t *array = create_array(len);

    for (int i = 0; i < len; i++)
    {
        array->array_pasien[i] = input_pasien();
    }

    int temp1 = berat_terendah(array);
    int temp2 = tinggi_terendah(array);

    print_array(array);
    print_lainnya(array, temp2, temp1);
}