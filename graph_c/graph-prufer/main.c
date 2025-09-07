#include "graph.h"

int main(void){
    system("cls");
    int menu;
    printf("\tMenu\n\n\t1. Tree\n\t2. Prufer Code\n\n\tChoose: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
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
        if (is_tree(graph))
        {
            printf("Prufer Codes:\n{ ");
            int *array = prufer_codes(graph);
            for (int i = 0; i < len-2; i++)
            {
                printf("%d ", array[i]);
            }
            printf("}");
            free(array);
            break;
        }

        printf("Your graph is not a tree, therefore there's no prufer codes for your graph.");
        break;
    
    case 2:
        system("cls");
        int len_prufer;
        printf("Length of the prufer codes array: ");
        scanf("%d", &len_prufer);

        int *prufer_array = calloc(len_prufer, sizeof(int));
        printf("Insert the prufer codes to the corresponding array index\n");
        for (int i = 0; i < len_prufer; i++)
        {
            printf("\t[%d]: ", i);
            scanf("%d", &prufer_array[i]);
        }

        graph_t *prufer_graph = convert_code(prufer_array, len_prufer);
        print_graph(prufer_graph);
        
        free(prufer_array);
        break;

    default:
        break;
    }

    return 0;
}