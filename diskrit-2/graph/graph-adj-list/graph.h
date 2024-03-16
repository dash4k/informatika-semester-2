#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node_t;
typedef struct graph graph_t;

node_t *create_nodes(int vertex);
graph_t *create_graph(int vertices);
void add_edges(graph_t *graph, int vertex_a, int vertex_b);
void print_graph(graph_t *graph);
void dfs(graph_t *graph, int random_start, int *connected);
void is_connected(graph_t *graph);
void is_directed(graph_t *graph);

#endif