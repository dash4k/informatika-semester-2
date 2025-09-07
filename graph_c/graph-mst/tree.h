#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct graph graph_t;
typedef struct edge edge_t;
typedef struct array edge_array;

graph_t *create_graph(int vertices);
void add_edge(graph_t *graph, int vertex_a, int vertex_b, int edge_weight);
void print_graph(graph_t *graph);
graph_t *create_mst_prim(graph_t *graph);
void sort_edge_array(edge_array *array);
void merge_union(int *array, int len, int edge_1, int edge_2);
graph_t *create_mst_kruskal(graph_t *graph);

#endif