#include "graph.h"

struct graph{
    int vertices;
    bool **edges;
};

graph_t *create_graph(int vertices){
    graph_t *new_graph = malloc(sizeof(graph_t));
    new_graph->vertices = vertices;
    new_graph->edges = calloc(new_graph->vertices, sizeof(bool*));
    for (int i = 0; i < new_graph->vertices; i++)
    {
        new_graph->edges[i] = calloc(new_graph->vertices, sizeof(bool));
    }
    
    return new_graph;
}

void add_edges(graph_t *graph, int vertex_a, int vertex_b){
    if (graph->edges[vertex_a][vertex_b])
    {
        return;
    }
    
    graph->edges[vertex_a][vertex_b] = true;
    graph->edges[vertex_b][vertex_a] = true;
}

void print_graph(graph_t *graph){
    printf("\nYour Graph:\n\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("\t%d ", i);
    }

    printf("\n\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%d", i);
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[i][j])
            {
                printf("\tx");
            }
            else
            {
                printf("\t-");
            }
            
            
        }
        printf("\n");   
    }
    
}

bool is_cycle(graph_t *graph, int random_start, int parent, bool *reach){
    reach[random_start] = true;
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->edges[random_start][i])
        {
            if (!reach[i])
            {
                if (is_cycle(graph, i, random_start, reach))
                {
                    return true;
                }
                
            }
            else if (i != parent)
            {
                return true;
            }
            
        }
        
    }
    return false;
}

bool is_tree(graph_t *graph){
    bool *reach = calloc(graph->vertices, sizeof(bool));
    for (int i = 0; i < graph->vertices; i++)
    {
        reach[i] = false;
    }

    if (is_cycle(graph, 0, -1, reach))
    {
        return false;
    }
    
    return true;
}