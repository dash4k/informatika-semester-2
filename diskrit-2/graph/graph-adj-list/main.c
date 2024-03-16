#include <stdio.h>
#include "graph.h"

int main(void){
    system("cls");
    int num, temp;

    printf("Number of vertices: ");
    scanf("%d", &num);

    graph_t *graph = create_graph(num);
    
    printf("Enter 1 if the vertices are connected, 0 if not connected\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
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

    printf("\n\nGraph Properties: ");
    is_connected(graph);
    is_directed(graph);
}