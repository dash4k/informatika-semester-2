#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct graph graph_t;

graph_t *create_graph(int vertices);
void add_edges(graph_t *graph, int vertex_a, int vertex_b);
void print_graph(graph_t *graph);
bool is_cycle(graph_t *graph, int random_start, int parent, bool *reach);
bool is_tree(graph_t *graph);
int **count_edges(graph_t *graph);
void sort_edges(int **array, int len);
int *prufer_codes(graph_t *graph);
bool find_value(int *array, int key, int len);
graph_t *convert_code(int *prufer_array, int len);

#endif