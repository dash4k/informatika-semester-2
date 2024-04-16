#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struct buku
typedef struct buku{
    char judul[50];
    int jumlah_halaman;
    char penerbit[50];
}buku_t;

// struct queue
typedef struct queue
{
    buku_t *data;
    int front;
    int rear;
    int queue_len;
}queue_t;

// utilities function definition
queue_t *create_queue(int len);
void enqueue(queue_t *queue, buku_t *buku);
int dequeue(queue_t *queue, buku_t* buku);
void add_book(queue_t *queue);
void remove_book(queue_t *queue);
bool yaqueen(void);

// main function
int main(void){
    system("cls");
    int len, menu;
    bool exit = false;
    printf("Program tumpukan buku :\n");
    printf("Ketik jml maksimum tumpukan : ");
    scanf("%d", &len);

    queue_t *queue = create_queue(len);

    do
    {
        system("cls");
        printf("\tMenu \n\n");
        printf("1. \tTambah Buku\n");
        printf("2. \tAmbil Buku\n");
        printf("3. \tKeluar\n\n");
        printf("Pilihan: ");
        scanf("%d", &menu);
        
        switch (menu)
        {
        case 1:
            if (yaqueen())
            {
                add_book(queue);
                printf("\n\n");
                system("pause");
            }
            break;
        
        case 2:
            if (yaqueen())
            {
                remove_book(queue);
                printf("\n\n");
                system("pause");
            }
            break;

        case 3:
            if (yaqueen())
            {
                exit = true;
            }
            break;
            
        default:
            break;
        }
    } while (!exit);
    
}

// create queue function
queue_t *create_queue(int len){
    queue_t *new_queue = malloc(sizeof(queue_t));
    new_queue->queue_len = len;
    new_queue->data = calloc(len, sizeof(buku_t));
    new_queue->front = -1;
    new_queue->rear = -1;

    return new_queue;
}

// insert to queue function
void enqueue(queue_t *queue, buku_t *buku){
    queue->data[++queue->rear] = *buku;
    return;
}

// remove from queue function
int dequeue(queue_t *queue, buku_t* buku){
    if (queue->front == queue->rear)
    {
        printf("Queue is empty");
        return 1;
    }
    
    *buku = queue->data[++queue->front];
    return 0;
}

//  add book function
void add_book(queue_t *queue){
    if (queue->rear == queue->queue_len -1)
    {
        printf("Queue is full");
        return;
    }

    buku_t *new_book = malloc(sizeof(buku_t));

    printf("Masukkan Judul Buku: ");
    getchar();
    fgets(new_book->judul, sizeof(new_book->judul), stdin);
    new_book->judul[strcspn(new_book->judul, "\r\n")] = 0;

    printf("Masukkan Penerbit: ");
    getchar();
    fgets(new_book->penerbit, sizeof(new_book->penerbit), stdin);
    new_book->penerbit[strcspn(new_book->penerbit, "\r\n")] = 0;

    printf("Masukkan Jumlah Halaman Buku: ");
    scanf("%d", &new_book->jumlah_halaman);
    
    enqueue(queue, new_book);
}

// remove book function
void remove_book(queue_t *queue){
    buku_t *temp_book = malloc(sizeof(buku_t));
    int status = dequeue(queue, temp_book);

    if (status == 1)
    {
        return;
    }
    
    printf("Buku dengan judul %s sudah diambil", temp_book->judul);
    free(temp_book);
}

// confirmation function
bool yaqueen(void){
    system("cls");
    char yakin;
    printf("Anda Yakin (Y/T): ");
    scanf(" %c", &yakin);

    if (yakin == 'Y' || yakin == 'y')
    {
        return true;
    }
    return false;
}