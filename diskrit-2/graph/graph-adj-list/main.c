#include <stdio.h>
#include "graph.h"

int main(void){
    graph_t *graph = create_graph(4);

    add_edges(graph, 1, 2);
    add_edges(graph, 0, 1);
    add_edges(graph, 1, 3);
    add_edges(graph, 0, 3);

    print_graph(graph);
}