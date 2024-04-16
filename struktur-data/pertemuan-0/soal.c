#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct mahasiswa
typedef struct mahasiswa
{
    char nama[50];
    float uts;
    float uas;
    float tugas;
    float kuis;
    float nilai_final;
    char nilai_mutu;
}mahasiswa_t;

// struct array mahasiswa
typedef struct array
{
    mahasiswa_t *mahasiswa;
    int total_mahasiswa;
}array_t;

// utilities function definition
mahasiswa_t create_mahasiswa();
char grade_check(mahasiswa_t mahasiswa);
array_t *create_array(int n);
void print_grade(array_t *array);

// main function
int main(void){
    system("cls");
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    array_t *array = create_array(n);

    print_grade(array);
}

// create mahasiswa function
mahasiswa_t create_mahasiswa(){
    system("cls");
    mahasiswa_t temp;

    getchar();
    printf("Nama Mahasiswa: ");
    fgets(temp.nama, sizeof(temp.nama), stdin);
    temp.nama[strcspn(temp.nama, "\r\n")] = 0;

    printf("Nilai UTS: ");
    scanf("%f", &temp.uts);

    printf("Nilai UAS: ");
    scanf("%f", &temp.uas);

    printf("Nilai Tugas: ");
    scanf("%f", &temp.tugas);

    printf("Nilai Kuis: ");
    scanf("%f", &temp.kuis);

    temp.nilai_final = (temp.uas * 0.3) + (temp.uts * 0.3) + (temp.tugas * 0.2) + (temp.kuis * 0.2);

    temp.nilai_mutu = grade_check(temp);

    return temp;
}

// final grading function
char grade_check(mahasiswa_t mahasiswa){
    if (80 <= mahasiswa.nilai_final)
    {
        return 'A';
    }
    else if (65 <= mahasiswa.nilai_final)
    {
        return 'B';
    }
    else if (50 <= mahasiswa.nilai_final)
    {
        return 'C';
    }
    else if (30 <= mahasiswa.nilai_final)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

// create array mahasiswa function
array_t *create_array(int n){
    array_t *temp = malloc(sizeof(array_t));
    temp->total_mahasiswa = n;
    temp->mahasiswa = calloc(temp->total_mahasiswa, sizeof(mahasiswa_t));

    for (int i = 0; i < temp->total_mahasiswa; i++)
    {
        temp->mahasiswa[i] = create_mahasiswa();
    }
    
    return temp;
}

// print nilai mutu mahasiswa function
void print_grade(array_t *array){
    system("cls");
    printf("\tNilai Mahasiswa: \n\n");
    for (int i = 0; i < array->total_mahasiswa; i++)
    {
        printf("%s, nilai mutu: %c\n", array->mahasiswa[i].nama, array->mahasiswa[i].nilai_mutu);
    }
    printf("\n");
}