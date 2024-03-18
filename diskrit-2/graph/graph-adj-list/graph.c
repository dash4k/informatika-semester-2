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
    node_t *temp = NULL;
    for (int i = 0; i < graph->vertices; i++)
    {
        temp = graph->Adjlist[i];
        printf("\nVertex %d: ", i);
        degree[i] = 0;
        
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
            degree[i]++;
        }
        printf("| degree: %d", degree[i]);
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
}

bool check_graph(graph_t *graph){
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
        return false;
    }
    else
    {
        return true;
    }
    
}

void is_connected(graph_t *graph){
    if (!check_graph(graph))
    {
        printf("\nNot a Graph");
        return;
    }
    
    int *reach = calloc(graph->vertices, sizeof(int));
    int count;
    
    for (int i = 0; i < graph->vertices; i++)
    {
        count = 0;
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
    printf("\nGraph is Disconnected");
}

void is_directed(graph_t *graph){
    if (!check_graph(graph))
    {
        return;
    }
    

    int *reach1 = calloc(graph->vertices, sizeof(int));
    int *reach2 = calloc(graph->vertices, sizeof(int));

    dfs(graph, 0, reach1);
    dfs(graph, 1, reach2);

    for (int i = 0; i < graph->vertices; i++)
    {
        if ((reach1[i] && !reach2[i]) || (!reach1[i] && reach2[i]))
        {
            printf("\nGraph is Directed");
            return;
        }
        
    }
    printf("\nGraph is Undirected");
}

void count_degree(graph_t *graph, int* degrees){
    node_t *temp;
    for (int i = 0; i < graph->vertices; i++)
    {
        degrees[i] = 0;
        temp = graph->Adjlist[i];
        while (temp)
        {
            degrees[i]++;
            temp = temp->next;
        }
        
    }
    
}

void sort_graph_by_degree(graph_t *graph){
    int *degrees = calloc(graph->vertices, sizeof(int));
    node_t *temp_node;
    int temp_int;
    count_degree(graph, degrees);

    for (int  i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            if (degrees[i] < degrees[j+1])
            {
                temp_int = degrees[j];
                degrees[j] = degrees[j+1];
                degrees[j+1] = temp_int;

                temp_node = graph->Adjlist[j];
                graph->Adjlist[j] = graph->Adjlist[j+1];
                graph->Adjlist[j+1] = temp_node;
            }
            
        }
        
    }
    
}

void greedy_coloring(graph_t *graph){
    if (!check_graph(graph))
    {
        printf("Undefined");
        return;
    }

    int *result = calloc(graph->vertices, sizeof(int));
    bool *available = calloc(graph->vertices, sizeof(bool));
    sort_graph_by_degree(graph);

    for (int i = 0; i < graph->vertices; i++) {
        result[i] = -1;
        available[i] = true;
    }

    result[0] = 0;

    // Special case if the user ONLY inputted two vertices
    if (graph->vertices == 2) {
        result[0] = 0;
        result[1] = 1;
        for (int i = 0; i < graph->vertices; i++)
        {
            printf("Vertex %d --->  Color %d\n", i, result[i]);
        }
        return;
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        node_t *temp = graph->Adjlist[i];
        int j = 0;
        while (temp)
        {
            if (result[j] != -1)
            {
                available[result[j]] = false;
            }
            temp = temp->next;
            j++;
        }

        
        int cr;
        for (cr = 0; cr < graph->vertices; cr++){
            if (available[cr]){
                break;
            }
        }

        result[i] = cr;

        j = 0;
        temp = graph->Adjlist[i];
        while (temp)
        {
            if (result[j] != -1)
            {
                available[result[j]] = true;
            }
            temp = temp->next;
            j++;
        }
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("Vertex %d --->  Color %d\n", i, result[i]);
    }
}