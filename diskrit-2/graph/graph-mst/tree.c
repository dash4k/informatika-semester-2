#include "tree.h"

struct graph{
    int vertices;
    int **edges;
};

graph_t *create_graph(int vertices){
    graph_t *new_graph = malloc(sizeof(graph_t));
    new_graph->vertices = vertices;
    new_graph->edges = calloc(new_graph->vertices, sizeof(int*));
    for (int i = 0; i < new_graph->vertices; i++)
    {
        new_graph->edges[i] = calloc(new_graph->vertices, sizeof(int));
        for (int j = 0; j < new_graph->vertices; j++)
        {
            new_graph->edges[i][j] = 0;
        }
        
    }
    return new_graph;
}

void add_edge(graph_t *graph, int vertex_a, int vertex_b, int edge_weight){
    if (graph->edges[vertex_a][vertex_b] != 0)
    {
        return;
    }
    graph->edges[vertex_a][vertex_b] = edge_weight;
    graph->edges[vertex_b][vertex_a] = edge_weight;
}

void print_graph(graph_t *graph){
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("\t%d", i);
    }
    printf("\n\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%d", i);
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[i][j] != 0)
            {
                printf("\t%d", graph->edges[i][j]);
            }
            else
            {
                printf("\t-");
            }
            
            
        }
        printf("\n");
    }
    
}

graph_t *create_mst(graph_t *graph){
    graph_t *new_tree = create_graph(graph->vertices);

    bool *selected = calloc(graph->vertices, sizeof(bool));
    for (int i = 0; i < graph->vertices; i++)
    {
        selected[i] = false;
    }

    int edges = 0;
    int row, col, min;

    selected[0] = true;
    while (edges < graph->vertices - 1)
    {
        min = 99999;
        row = 0;
        col = 0;
        for (int i = 0; i < graph->vertices; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < graph->vertices; j++)
                {
                    if (!selected[j] && graph->edges[i][j])
                    {
                        if (min > graph->edges[i][j])
                        {
                            min = graph->edges[i][j];
                            row = i;
                            col = j;
                        }
                        
                    }
                    
                }
                
            }
            
        }

        add_edge(new_tree, row, col, graph->edges[row][col]);
        selected[col] = true;
        edges++;
        
    }
    
    return new_tree;
}