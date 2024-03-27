#include "tree.h"

int main(void){
    int len, weight;
    printf("Enter the length: ");
    scanf("%d", &len);
    
    graph_t *graph = create_graph(len);
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            printf("%d --> %d: ", i, j);
            scanf("%d", &weight);
            if (weight != 0)
            {
                add_edge(graph, i, j, weight);
            }
            
        }
        
    }

    system("cls");
    printf("\n\n");
    printf("Graph: \n\n");
    print_graph(graph);
    printf("\n\n");

    printf("MST Prim: \n\n");
    graph_t *mst = create_mst_prim(graph);
    print_graph(mst);
    printf("\n\n");

    printf("MST Kruskal: \n\n");
    graph_t *mst1 = create_mst_kruskal(graph);
    print_graph(mst1);
    
}