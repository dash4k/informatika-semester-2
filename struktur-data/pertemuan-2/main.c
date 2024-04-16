#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct pasien
typedef struct pasien
{
    char nama[50];
    int berat;
    int tinggi;
}pasien_t;

// struct array pasien
typedef struct array
{
    int jumlah_pasien;
    pasien_t *array_pasien;
}array_t;

// utilities function definition
array_t *create_array(int jumlah);
pasien_t input_pasien();
int berat_terendah(array_t *array_pasien);
float berat_rerata(array_t *array_pasien);
int tinggi_terendah(array_t *array_pasien);
float tinggi_rerata(array_t *array_pasien);
void print_array(array_t *array_pasien);
void print_lainnya(array_t *array_pasien, int index_tinggi, int index_berat);

// main function
int main(void){
    system("cls");
    int len;
    printf("Masukkan jumlah pasien: ");
    scanf("%d", &len);

    array_t *array = create_array(len);

    int temp1 = berat_terendah(array);
    int temp2 = tinggi_terendah(array);

    print_array(array);
    print_lainnya(array, temp2, temp1);
}

// create array function
array_t *create_array(int jumlah){
    array_t *array = malloc(sizeof(array_t));
    array->jumlah_pasien = jumlah;
    array->array_pasien = calloc(array->jumlah_pasien, sizeof(pasien_t));

    for (int i = 0; i < array->jumlah_pasien; i++)
    {
        array->array_pasien[i] = input_pasien();
    }

    return array;
}

//create pasien function
pasien_t input_pasien(){
    printf("\n");
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

// lowest weight index function
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

// average weight function
float berat_rerata(array_t *array_pasien){
    float berat_rerata = 0;
    for (int i = 0; i < array_pasien->jumlah_pasien; i++)
    {
        berat_rerata += array_pasien->array_pasien[i].berat;
    }
    return berat_rerata / array_pasien->jumlah_pasien;
}

// lowest height index function
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

// average height function
float tinggi_rerata(array_t *array_pasien){
    float tinggi_rerata = 0;
    for (int i = 0; i < array_pasien->jumlah_pasien; i++)
    {
        tinggi_rerata += array_pasien->array_pasien[i].tinggi;
    }
    return tinggi_rerata / array_pasien->jumlah_pasien;
}

// print array function
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

// print other attributes function
void print_lainnya(array_t *array_pasien, int index_tinggi, int index_berat){
    printf("Berat Rata-Rata: %f\n", berat_rerata(array_pasien));
    printf("Tinggi Rata-Rata: %f\n", tinggi_rerata(array_pasien));
    printf("\n");
    printf("Berat terendah: %s dengan berat %d Ton\n", array_pasien->array_pasien[index_berat].nama, array_pasien->array_pasien[index_berat].berat);
    printf("Tinggi terendah: %s dengan tinggi %d Meter\n", array_pasien->array_pasien[index_tinggi].nama, array_pasien->array_pasien[index_tinggi].tinggi);
}