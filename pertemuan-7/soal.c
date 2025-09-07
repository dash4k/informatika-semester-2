#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{
    int data;
    int key;
}hash_t;

void clear_screen(void);
int square(int x);
int linear_index(hash_t *hash_table, int k, int m);
hash_t *linear_probing(int *array, int size);
int quadratic_index(hash_t *hash_table, int k, int i, int m);
hash_t *quadratic_probing(int *array, int size);

int main(void){
    clear_screen();
    int size, temp;
    printf("Ketik jumlah bilangan: ");
    scanf("%d", &size);
    int array[size];
    clear_screen();
    printf("Masukkan Bilangan\n");
    for (int i = 0; i < size; i++)
    {
        printf("Bilangan-%d: ", i+1);
        scanf("%d", &temp);
        array[i] = temp;
    }
    printf("\n");
    hash_t *linear_array = linear_probing(array, size);
    hash_t *quadratic_array = quadratic_probing(array, size);
    printf("Data Tersimpan (Linear Probing)\n");
    for (int i = 0; i < size; i++)
    {
        if (linear_array[i].data == 0)
        {
            printf("Index %d: Kosong\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, linear_array[i].data);
        }
    }
    printf("\n");
    printf("Data Tersimpan (Quadratic Probing)\n");
    for (int i = 0; i < size; i++)
    {
        if (quadratic_array[i].data == 0)
        {
            printf("Index %d: Kosong\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, quadratic_array[i].data);
        }
    }
}

void clear_screen(void){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int square(int x){
    return x * x;
}

int linear_index(hash_t *hash_table, int k, int m){
    int index = k % m;
    if (hash_table[index].data != 0)
    {
        return linear_index(hash_table, k+1, m);
    }
    else
    {
        return index;
    }
    
}

hash_t *linear_probing(int *array, int size){
    hash_t *linear_array = calloc(sizeof(hash_t), size);
    int temp, index;
    for (int i = 0; i < size; i++)
    {
        linear_array[i].data = 0;
        linear_array[i].key = 0;
    }
    for (int i = 0; i < size; i++)
    {
        temp = array[i];
        index = linear_index(linear_array, temp, size);
        linear_array[index].key = index;
        linear_array[index].data = temp;
    }
    return linear_array;
}

int quadratic_index(hash_t *hash_table, int k, int i, int m){
    int index = (k + square(i)) % m;
    if (hash_table[index].data != 0)
    {
        return quadratic_index(hash_table, k, i+1, m);
    }
    else
    {
        return index;
    }
    
}

hash_t *quadratic_probing(int *array, int size){
    hash_t *linear_array = calloc(sizeof(hash_t), size);
    int temp, index;
    for (int i = 0; i < size; i++)
    {
        linear_array[i].data = 0;
        linear_array[i].key = 0;
    }
    for (int i = 0; i < size; i++)
    {
        temp = array[i];
        index = quadratic_index(linear_array, temp, 0, size);
        linear_array[index].key = index;
        linear_array[index].data = temp;
    }
    return linear_array;
}