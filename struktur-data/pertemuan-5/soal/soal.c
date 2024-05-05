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
}mahasiwa_t;

typedef struct queue
{
    mahasiwa_t mahasiswa;
    struct queue *next;
}queue_t;

mahasiwa_t create_mahasiswa();
queue_t *create_queue();
void enqueue(queue_t **head, queue_t *new_queue);
void dequeue(queue_t **head);
void print_queue(queue_t *head);
void pause();
void clear_screen();
bool yakin(void);

int main(void){
    queue_t *head = NULL, *new = NULL; 
    int menu, nominal, kembalian;
    bool exit = false;

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
            new = create_queue();
            enqueue(&head, new);
            break;
        
        case 2:
            clear_screen();
            if (head == NULL)
            {
                printf("The queue is currently empty\n\n");
                pause();
                break;
            }

            printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n");
            printf("%s \t\t %s \t\t\t %d \t\t %d\n\n", head->mahasiswa.nama, head->mahasiswa.nim, head->mahasiswa.ukt, head->mahasiswa.nominal_ukt);

            printf("\n\nNominal: ");
            scanf("%d", &nominal);
                
            kembalian = nominal - head->mahasiswa.nominal_ukt;
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
                    dequeue(&head);
                    printf("Kembalian: %d \n", kembalian);
                    pause();
                }
                break;
            }

        case 3:
            clear_screen();
            print_queue(head);
            printf("\n\n");
            pause();
            break;
        
        case 4:
            if (yakin())
            {
                exit = true;
            }
            break;
            
        default:
            break;
        }
    } while (!exit);
    
    
}

mahasiwa_t create_mahasiswa(){
    mahasiwa_t temp;

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

queue_t *create_queue(){
    queue_t *new_queue = malloc(sizeof(queue_t));
    new_queue->mahasiswa = create_mahasiswa();
    new_queue->next = NULL;

    return new_queue;
}

void enqueue(queue_t **head, queue_t *new_queue){
    queue_t *temp = *head;

    if (*head == NULL)
    {
        *head = new_queue;
        return;   
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = new_queue;
}

void dequeue(queue_t **head){
    queue_t *temp = *head;  
    
    *head = (*head)->next;
    free(temp);
}

void print_queue(queue_t *head){
    clear_screen();
    queue_t *temp = head;
    printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n\n");
    while (temp != NULL)
    {
        printf("%s \t\t %s \t\t\t %d \t\t %d", temp->mahasiswa.nama, temp->mahasiswa.nim, temp->mahasiswa.ukt, temp->mahasiswa.nominal_ukt);
        printf("\n");
        temp = temp->next;
    }
    
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