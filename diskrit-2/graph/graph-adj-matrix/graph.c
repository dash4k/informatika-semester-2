#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

struct mygraph
{
    int numnodes;
    bool **edges;
};


graph *create_graph(int numnodes) {
    graph *g = malloc(sizeof(*g));
    if (g == NULL)
    {
        return NULL;
    }

    g->numnodes = numnodes;

    // allocate out matrix
    g->edges = calloc(g->numnodes, sizeof(bool*));
    if (g == NULL)
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < g->numnodes; i++)
    {
        g->edges[i] = calloc(g->numnodes, sizeof(bool));
        if (g == NULL)
        {
            destroy_graph(g);
            return NULL;
        }
        
    }
    
    return g;
}

void destroy_graph(graph* g) {
    if (g->edges == NULL)
    {
        free(g);
        return;
    }
    
    for (int i = 0; i < g->numnodes; i++)
    {
        g->edges[i] = calloc(g->numnodes, sizeof(bool));
        if (g->edges[i] != NULL)
        {
            free(g->edges[i]);
        }
        
        free(g->edges);
    }
    
    free(g);
}

void print_graph(graph* g) {
    printf("disgraph {\n");

    for (int i = 0; i < g->numnodes; i++)
    {
        for (int j = 0; j < g->numnodes; j++)
        {
            if (g->edges[i][j])
            {
                printf("%d -> %d;\n", i, j);
            }
            
        }
        
    }
    
    printf("}\n");
}
bool add_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    if (has_edge(g, from_node, to_node))
    {
        return false;
    }
    
    g->edges[from_node][to_node] = true;
    return true;
}

bool has_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    return g->edges[from_node][to_node];
}