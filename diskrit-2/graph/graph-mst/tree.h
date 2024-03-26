#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct graph graph_t;

graph_t *create_graph(int vertices);
void add_edge(graph_t *graph, int vertex_a, int vertex_b, int edge_weight);
void print_graph(graph_t *graph);
graph_t *create_mst(graph_t *graph);

#endif