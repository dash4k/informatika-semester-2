#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct node
{
    int vertex;
    struct node* next;
} node_t;

typedef struct graph
{
    int verticies;
    struct node** Adjlist;
} graph_t;


node_t *create_nodes(int vertex){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

graph_t *create_graph(int verticies){
    graph_t *new_graph = malloc(sizeof(graph_t));
    new_graph->verticies = verticies;
    new_graph->Adjlist = malloc(verticies * sizeof(node_t));

    for (int i = 0; i < verticies; i++)
    {
        new_graph->Adjlist[i] = NULL;
    }
    
    return new_graph;
}

void add_edges(graph_t *graph, int a, int b){
    
    // edge a ke b
    node_t *temp = create_nodes(b);
    temp->next = graph->Adjlist[a];
    graph->Adjlist[a] = temp;

    // edge b ke a
    temp = create_nodes(a);
    temp->next = graph->Adjlist[b];
    graph->Adjlist[b] = temp;
}

void print_graph(graph_t *graph){
    for (int i = 0; i < graph->verticies; i++)
    {
        node_t *temp = graph->Adjlist[i];
        printf("\n Vertex %d: ", i);
        
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

    }
    printf("\n");    
}