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
    if (is_tree(graph))
    {
        printf("\nYour graph is a tree");
    }
    
}