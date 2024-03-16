#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "graph.h"

typedef struct node
{
    int vertex;
    struct node* next;
} node_t;

typedef struct graph
{
    int vertices;
    struct node** Adjlist;
} graph_t;


node_t *create_nodes(int vertex){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

graph_t *create_graph(int vertices){
    graph_t *new_graph = malloc(sizeof(graph_t));
    new_graph->vertices = vertices;
    new_graph->Adjlist = calloc(sizeof(node_t), new_graph->vertices);

    for (int i = 0; i < vertices; i++)
    {
        new_graph->Adjlist[i] = NULL;
    }
    
    return new_graph;
}

void add_edges(graph_t *graph, int vertex_a, int vertex_b){
    node_t *temp = create_nodes(vertex_b);
    temp->next = graph->Adjlist[vertex_a];
    graph->Adjlist[vertex_a] = temp;
}

void print_graph(graph_t *graph){
    int *degree = calloc(graph->vertices, sizeof(int));
    printf("\nAdjacency List:");
    for (int i = 0; i < graph->vertices; i++)
    {
        node_t *temp = graph->Adjlist[i];
        printf("\nVertex %d: ", i);
        
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
            degree[i]++;
        }
        printf("| degree: %d", degree[i]);
        free(temp);
    }
}

void dfs(graph_t *graph, int random_start, int *reach){
    reach[random_start] = 1;
    node_t *temp = graph->Adjlist[random_start];
    while (temp)
    {
        if (reach[temp->vertex] != 1)
        {
            dfs(graph, temp->vertex, reach);
        }
        temp = temp->next;
    }
    free(temp);
}

void is_connected(graph_t *graph){
    int count_check = 0;
    node_t *check;
    for (int i = 0; i < graph->vertices; i++)
    {
        check = graph->Adjlist[i];
        if (check == NULL)
        {
            count_check++;
        }
    }

    if (count_check == graph->vertices)
    {
        printf("\n\nNot a Graph");
        free(check);
        return;
    }
    
    int *reach = calloc(graph->vertices, sizeof(int));
    
    for (int i = 0; i < graph->vertices; i++)
    {
        int count = 0;
        for (int j = 0; j < graph->vertices; j++)
        {
            reach[j] = 0;
        }
        
        dfs(graph, i, reach);

        for (int j = 0; j < graph->vertices; j++)
        {
            if (reach[j])
            {
                count++;
            }
        }

        if (count == graph->vertices)
        {
            printf("\nGraph is Connected");
            return;
        }
    }
    printf("\nGraph is Unconnected");
}

void is_directed(graph_t *graph){
    int count_check = 0;
    node_t *check;
    for (int i = 0; i < graph->vertices; i++)
    {
        check = graph->Adjlist[i];
        if (check == NULL)
        {
            count_check++;
        }
    }

    if (count_check == graph->vertices)
    {
        free(check);
        return;
    }

    int *ptr1 = calloc(graph->vertices, sizeof(int));
    int *ptr2 = calloc(graph->vertices, sizeof(int));

    dfs(graph, 0, ptr1);
    dfs(graph, 1, ptr2);

    for (int i = 0; i < graph->vertices; i++)
    {
        if ((ptr1[i] && !ptr2[i]) || (!ptr1[i] && ptr2[i]))
        {
            printf("\nGraph is Directed");
            return;
        }
        
    }
    printf("\nGraph is Undirected");
}