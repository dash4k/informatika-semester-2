#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

typedef struct graph graph_t;

node_t *create_nodes(int vertex);
graph_t *create_graph(int verticies);
void add_edges(graph_t *graph, int a, int b);
void print_graph(graph_t *graph);
void check_connectivity(graph_t *graph, int random, int *reach);

#endif