#include <stdio.h>
#include "graph.h"

int main(void){
    int num = 5, count = 0;
    graph_t *graph = create_graph(num);

    int *reach = calloc(num, sizeof(int));

    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            add_edges(graph, i, j);
        }
        
    }
    


    print_graph(graph);

    check_connectivity(graph, 2, reach);

    for (int i = 0; i < num; i++)
    {
        if (reach[i])
        {
            count++;
        }
        
    }

    if (count == num)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
}