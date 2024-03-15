#include <stdio.h>
#include "graph.h"

int main(void){
    int num = 3, count = 0;
    graph_t *graph = create_graph(num);

    int *reach = calloc(num, sizeof(int));

    add_edges(graph, 0, 1);
    add_edges(graph, 1, 2);
    add_edges(graph, 0, 2);


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