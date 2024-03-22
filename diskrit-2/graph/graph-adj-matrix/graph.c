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

int **count_edges(graph_t *graph){
    int **array = calloc(graph->vertices, sizeof(int*));
    for (int i = 0; i < graph->vertices; i++)
    {
        array[i] = calloc(2, sizeof(int));
    }
    
    for (int i = 0; i < graph->vertices; i++)
    {
        array[i][0] = i;
        array[i][1] = 0;
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[i][j])
            {
                array[i][1]++;
            }
            
        }
        
    }

    return array;
    
}

void sort_edges(int **array, int len){
    int temp1, temp2;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (array[j][1] > array[j+1][1] || (array[j][1] == array[j+1][1] && array[j][0] > array[j+1][0]))
            {
                temp1 = array[j+1][0];
                temp2 = array[j+1][1];
                array[j+1][0] = array[j][0];
                array[j+1][1] = array[j][1];
                array[j][0] = temp1;
                array[j][1] = temp2;
            }
        }
    }
}

int *prufer_codes(graph_t *graph){
    int *prufer_array = calloc((graph->vertices-2), sizeof(int));
    int **degrees = count_edges(graph);
    int next;

    for (int i = 0; i < graph->vertices-2; i++)
    {
        sort_edges(degrees, graph->vertices);
        next = -1;
        for (int j = 0; j < graph->vertices; j++)
        {
            if (graph->edges[degrees[i][0]][j])
            {
                next = j;
                break;
            }
            
        }
        if (next != -1)
        {
            prufer_array[i] = next;
            graph->edges[degrees[i][0]][next] = graph->edges[next][degrees[i][0]] = false;
            degrees[i][1]--;
            for (int j = 0; j < graph->vertices; j++)
            {
                if (degrees[j][0] == next)
                {
                    degrees[j][1]--;
                }
                
            }
            
        }
    }
    return prufer_array;
}

bool find_value(int *array, int key, int len){
    for (int i = 0; i < len; i++)
    {
        if (array[i] == key)
        {
            return true;
        }
        
    }
    return false;
}

graph_t *convert_code(int *prufer_array, int len){
    int len1 = len + 2;
    int *array = calloc((len1), sizeof(int));
    for (int i = 0; i < len1; i++)
    {
        array[i] = i;
    }
    
    graph_t *temp_graph = create_graph(len1);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (!find_value(prufer_array, array[j], len) && array[j] != -1)
            {
                add_edges(temp_graph, prufer_array[i], array[j]);
                array[j] = -1;
                break;
            }
        }
        
    }
    
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (array[i] != -1 && array[j] != -1 && array[i] != array[j])
            {
                add_edges(temp_graph, array[i], array[j]);
                break;
            }
            
        }
        
    }
    
    free(array);
    return temp_graph;
}