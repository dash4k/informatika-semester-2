#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct mahasiswa
{
    char nama[50];
    char nim[50];
    int golongan_ukt;
    int nominal_ukt;
}mahasiswa_t;

typedef struct node
{
    mahasiswa_t mahasiswa;
    struct node *next;
    struct node *prev;
}node_t;


mahasiswa_t create_mahasiswa();
node_t *innit_node();
void enqueue(node_t **head, node_t **tail, node_t *new_node);
void dequeue(node_t **head, node_t **tail);
void print_nodes(node_t *head);
void pause();
void clear_screen();
bool yakin(void);

int main(){
    node_t *head = NULL, *tail = NULL, *new = NULL; 
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
            new = innit_node();
            enqueue(&head, &tail, new);
            break;
        
        case 2:
            clear_screen();
            if (head == NULL)
            {
                printf("Antrian kosong!\n\n");
                pause();
                break;
            }

            printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n");
            printf("%s \t\t %s \t\t\t %d \t\t %d\n\n", head->mahasiswa.nama, head->mahasiswa.nim, head->mahasiswa.golongan_ukt, head->mahasiswa.nominal_ukt);

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
                    dequeue(&head, &tail);
                    printf("Kembalian: %d \n", kembalian);
                    pause();
                }
                break;
            }

        case 3:
            clear_screen();

            if (head == NULL)
            {
                printf("Antrian kosong!\n\n");
                pause();
                break;
            }

            print_nodes(head);
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
    scanf("%d", &temp.golongan_ukt);

    switch (temp.golongan_ukt)
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
        temp.nominal_ukt = 15000000;
        break;
    }
    return temp;
}

node_t *innit_node(){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->mahasiswa = create_mahasiswa();
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void enqueue(node_t **head, node_t **tail, node_t *new_node){
    if (*head == NULL)
    {
        *head = new_node;
        new_node->next = *head;
        new_node->prev = *head;
        *tail = *head;
        return;
    }
    else
    {
        (*head)->prev = new_node;
        (*tail)->next = new_node;
        new_node->prev = *tail;
        new_node->next = *head;
        *tail = (*tail)->next;
        return;
    }
    
}

void dequeue(node_t **head, node_t **tail){
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        node_t *temp = *head;
        *head = NULL;
        *tail = NULL;
        free(temp);
        return;
    }
    else
    {
        node_t *temp = *head;
        *head = (*head)->next;
        (*head)->prev = *tail;
        (*tail)->next = *head;
        free(temp);
        return;
    }    
}

void print_nodes(node_t *head){
    clear_screen();
    node_t *temp = head;
    printf("NAMA \t\t\t NIM \t\t\t\t UKT \t\t NOMINAL\n\n");
    if ((*head).next == head)
    {
        printf("%s \t\t %s \t\t\t %d \t\t %d", temp->mahasiswa.nama, temp->mahasiswa.nim, temp->mahasiswa.golongan_ukt, temp->mahasiswa.nominal_ukt);
        printf("\n");
        return;
    }
    else
    {
        do
        {
            printf("%s \t\t %s \t\t\t %d \t\t %d", temp->mahasiswa.nama, temp->mahasiswa.nim, temp->mahasiswa.golongan_ukt, temp->mahasiswa.nominal_ukt);
            printf("\n");
            temp = temp->next;
        } while (temp != head);
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