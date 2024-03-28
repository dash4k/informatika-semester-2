#include "tree.h"

struct graph{
    int vertices;
    int **edges;
};

struct edge
{
    int col, row, weight;
};

struct array
{
    edge_t *data;
    int edges;
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

graph_t *create_mst_prim(graph_t *graph){
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

int count_edges(graph_t* graph){
    int count = 0;
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[i][j] != 0)
            {
                count++;
            }
            
        }
        
    }
    return count;
}

void sort_edge_array(edge_array *array){
    edge_t temp;
    for (int i = 0; i < array->edges; i++)
    {
        for (int j = 0; j < array->edges-1; j++)
        {
            if (array->data[j].weight > array->data[j+1].weight)
            {
                temp = array->data[j];
                array->data[j] = array->data[j+1];
                array->data[j+1] = temp;
            }
            
        }
        
    }
}

void merge_union(int *array, int len, int edge_1, int edge_2){
    for (int i = 0; i < len; i++)
    {
        if (array[i] == edge_2)
        {
            array[i] = edge_1;
        }
        
    }
    
}

graph_t *create_mst_kruskal(graph_t *graph){
    graph_t *new_tree = create_graph(graph->vertices);

    int *union_array = calloc(graph->vertices, sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
    {
        union_array[i] = i;
    }
    
    int total_edges = count_edges(graph);
    int vertex_1, vertex_2;

    edge_array *temp_array = malloc(sizeof(edge_array));
    temp_array->data = calloc(total_edges, sizeof(edge_t));
    temp_array->edges = 0;

    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = i; j < graph->vertices; j++)
        {
            if (graph->edges[i][j] != 0)
            {
                temp_array->data[temp_array->edges].col = i;
                temp_array->data[temp_array->edges].row = j;
                temp_array->data[temp_array->edges].weight = graph->edges[i][j];
                temp_array->edges++;
            }
            
        }
        
    }

    edge_array *real_array = malloc(sizeof(edge_array));
    real_array->data = calloc(temp_array->edges, sizeof(edge_t));
    real_array->edges = 0;

    sort_edge_array(temp_array);

    for (int i = 0; i < temp_array->edges; i++)
    {
        vertex_1 = union_array[temp_array->data[i].col];
        vertex_2 = union_array[temp_array->data[i].row];

        if (vertex_1 != vertex_2)
        {
            real_array->data[i] = temp_array->data[i];
            real_array->edges++;
            merge_union(union_array, graph->vertices, vertex_1, vertex_2);
        }
        
    }

    for (int i = 0; i < real_array->edges; i++)
    {
        add_edge(new_tree, real_array->data[i].col, real_array->data[i].row, real_array->data[i].weight);
    }
    
    
    return new_tree;
}