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
    new_graph->Adjlist = calloc(sizeof(node_t), new_graph->verticies);

    for (int i = 0; i < verticies; i++)
    {
        new_graph->Adjlist[i] = NULL;
    }
    
    return new_graph;
}

void add_edges(graph_t *graph, int vertex_a, int vertex_b){

    //directed
    node_t *temp = create_nodes(vertex_b);
    temp->next = graph->Adjlist[vertex_a];
    graph->Adjlist[vertex_a] = temp;

    // undirected
    // node_t *temp = create_nodes(vertex_b);
    // temp->next = graph->Adjlist[vertex_a];
    // graph->Adjlist[vertex_a] = temp;
    // temp = create_nodes(vertex_a);
    // temp->next = graph->Adjlist[vertex_b];
    // graph->Adjlist[vertex_b] = temp;
}

void print_graph(graph_t *graph){
    int degree = 0;
    for (int i = 0; i < graph->verticies; i++)
    {
        node_t *temp = graph->Adjlist[i];
        printf("\nVertex %d: ", i);
        
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
            degree++;
        }

    }
    printf("\n");    
    printf("\nGraph degree: %d", degree);    
}

void check_connectivity(graph_t *graph, int random, int *reach){
    reach[random] = 1;
    node_t *temp = graph->Adjlist[random];
    while (temp)
    {
        if (reach[temp->vertex] != 1)
        {
            printf("\n %d->%d", random, temp->vertex);
            check_connectivity(graph, temp->vertex, reach);
        }
        temp = temp->next;
    }
    free(temp);
}