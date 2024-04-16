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

// struct stack
typedef struct stack
{
    buku_t *data;
    int top;
    int stack_len;
}stack_t;

// utilities function definition
stack_t *create_stack(int len);
void push(stack_t *stack, buku_t *buku);
int pop(stack_t *stack, buku_t* buku);
void add_book(stack_t *stack);
void remove_book(stack_t *stack);
bool yaqueen(void);

// main function
int main(void){
    system("cls");
    int len, menu;
    bool exit = false;
    printf("Program tumpukan buku:\n");
    printf("Ketik jumlah maksimum tumpukan: ");
    scanf("%d", &len);

    stack_t *stack = create_stack(len);

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
                add_book(stack);
                printf("\n\n");
                system("pause");
            }
            break;
        
        case 2:
            if (yaqueen())
            {
                remove_book(stack);
                printf("\n\n");
                system("pause");
            }
            break;

        case 3:
            if (yaqueen())
            {
                printf("Terimakasih!\n");
                exit = true;
            }
            break;
            
        default:
            break;
        }
    } while (!exit);
    
}

// create stack function
stack_t *create_stack(int len){
    stack_t *new_stack = malloc(sizeof(stack_t));
    new_stack->stack_len = len;
    new_stack->data = calloc(len, sizeof(buku_t));
    new_stack->top = -1;

    return new_stack;
}

// insert to stack function
void push(stack_t *stack, buku_t *buku){
    stack->data[++stack->top] = *buku;
    return;
}

// remove from stack function
int pop(stack_t *stack, buku_t* buku){
    if (stack->top == -1)
    {
        printf("Stack is empty");
        return 1;
    }
    
    *buku = stack->data[stack->top--];
    return 0;
}

//  add book function
void add_book(stack_t *stack){
    if (stack->top == stack->stack_len -1)
    {
        printf("Stack is full");
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
    
    push(stack, new_book);
}

// remove book function
void remove_book(stack_t *stack){
    buku_t *temp_book = malloc(sizeof(buku_t));
    int status = pop(stack, temp_book);

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