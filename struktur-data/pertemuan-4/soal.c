#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct mahasiswa
{
    char nama[50];
    char nim[50];
    int ukt;
    int nominal_ukt;
}mahasiswa_t;

typedef struct queue
{
    mahasiswa_t *mahasiswa;
    int head, tail, size;
}queue_t;

mahasiswa_t create_mahasiswa();
queue_t *create_queue(int size);
bool is_empty(queue_t *q);
bool is_full(queue_t *q);
void enqueue(queue_t *q);
void dequeue(queue_t *q);
void print_queue(queue_t *q);
void pause();
void clear_screen();
bool yakin(void);

int main(void){
    clear_screen();
    queue_t *q; 
    int menu, nominal, kembalian, size;
    bool exit = false;
    
    printf("Masukkan jumlah maksimal antrian dalam satu kurun waktu (size > 1): ");
    scanf("%d", &size);

    q = create_queue(size);

    do
    {
        clear_screen();
        printf("Menu: \n\n");
        printf("1.\tTambah Antrian\n");
        printf("2.\tProses Pembayaran\n");
        printf("3.\tLihat Antrian\n");
        printf("4.\tKeluar\n\n");
        printf("Pilihan: ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            clear_screen();
            if (is_full(q))
            {
                clear_screen();
                printf("Antrian penuh! \n");
                pause();
                break;
            }
            else
            {
                enqueue(q);
                break;
            }
        
        case 2:
            if (is_empty(q))
            {
                clear_screen();
                printf("Antrian kosong! \n");
                pause();
                break;
            }
            else
            {
                clear_screen();
                printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n\n");
                printf("%s \t\t %s \t\t\t %d \t\t %d", q->mahasiswa[q->head].nama, q->mahasiswa[q->head].nim, q->mahasiswa[q->head].ukt, q->mahasiswa[q->head].nominal_ukt);
                printf("\n");

                printf("\n\nNominal: ");
                scanf("%d", &nominal);
                
                kembalian = nominal - q->mahasiswa[q->head].nominal_ukt;
                if (kembalian < 0)
                {
                    clear_screen();
                    printf("Nominal tidak cukup! \n\n");
                    pause();
                    break;
                }
                else
                {
                    if (yakin())
                    {
                        clear_screen();
                        dequeue(q);
                        printf("Kembalian: %d \n", kembalian);
                        pause();
                    }
                    break;
                }
            }

        case 3:
            if (is_empty(q))
            {
                clear_screen();
                printf("Antrian kosong! \n");
                pause();
                break;
            }
            else
            {
                clear_screen();
                print_queue(q);
                printf("\n\n");
                pause();
                break;
            }
        
        case 4:
            if (yakin())
            {
                exit = true;
                printf("Terimakasih!\n\n");
            }
            break;
            
        default:
            break;
        }
    } while (!exit);
    
    
}

mahasiswa_t create_mahasiswa(){
    mahasiswa_t temp;

    getchar();
    printf("Masukkan Nama: ");
    fgets(temp.nama, sizeof(temp.nama), stdin);
    temp.nama[strcspn(temp.nama, "\r\n")] = 0;

    printf("Masukkan NIM: ");
    fgets(temp.nim, sizeof(temp.nim), stdin);
    temp.nim[strcspn(temp.nim, "\r\n")] = 0;

    printf("Masukkan Golongan UKT: ");
    scanf("%d", &temp.ukt);

    switch (temp.ukt)
    {
    case 1:
        temp.nominal_ukt = 0;
        break;
    
    case 2:
        temp.nominal_ukt = 1000000;
        break;

    case 3:
        temp.nominal_ukt = 5000000;
        break;

    case 4:
        temp.nominal_ukt = 8000000;
        break;

    default:
        break;
    }
    return temp;
}

queue_t *create_queue(int size){
    queue_t *new_queue = malloc(sizeof(queue_t));
    new_queue->size = size;
    new_queue->mahasiswa = calloc(sizeof(mahasiswa_t), new_queue->size);
    new_queue->head = -1;
    new_queue->tail = -1;

    return new_queue;
}

bool is_empty(queue_t *q){
    return q->head == -1;
}

bool is_full(queue_t *q){
    return (q->tail + 1) % q->size == q->head;
}

void enqueue(queue_t *q){
    if (is_empty(q))
    {
        q->head++;
    }
    q->tail = (q->tail + 1) % q->size;
    q->mahasiswa[q->tail] = create_mahasiswa();
    return;
}

void dequeue(queue_t *q){
    if (q->tail == q->head)
    {
        q->head = q->tail = -1;
    }
    else
    {
        q->head = (q->head + 1) % q->size;
        return;
    }
}

void print_queue(queue_t *q){
    int temp = q->head;
    clear_screen();
    printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n\n");
    do
    {
        printf("%s \t\t %s \t\t\t %d \t\t %d", q->mahasiswa[temp].nama, q->mahasiswa[temp].nim, q->mahasiswa[temp].ukt, q->mahasiswa[temp].nominal_ukt);
        printf("\n");
        temp = (temp + 1) % q->size;
    } while (temp != (q->tail + 1) % q->size);
    return;
}

void pause(){
    char status;
    do
    {
        printf("Press Enter to Continue.........");
        getchar();
        scanf("%c", &status);
    } while (status != '\n');
    
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool yakin(void){
    clear_screen();
    char yakin;
    printf("Anda Yakin (Y/T): ");
    scanf(" %c", &yakin);

    if (yakin == 'Y' || yakin == 'y')
    {
        return true;
    }
    return false;
}