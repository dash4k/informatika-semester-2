#include "graph.h"

int main(void){
    system("cls");
    int len, temp;
    printf("Enter the length of the matrix: ");
    scanf("%d", &len);

    graph_t *graph = create_graph(len);

    printf("If these index of the matrix is adjacent input 1, else input 0\n");
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            printf("\t%d -> %d: ", i, j);
            scanf("%d", &temp);
            if (temp)
            {
                add_edges(graph, i, j);
            }
        }
        
    }
    

    print_graph(graph);
    printf("\n\n");
    printf("Prufer Codes:\n{ ");
    int *array = prufer_codes(graph);
    for (int i = 0; i < len-2; i++)
    {
        printf("%d ", array[i]);
    }
    printf("}");

    print_graph(graph);
    printf("\n\n");

    graph = convert_code(array, len-2);
    print_graph(graph);
    free(array);
}