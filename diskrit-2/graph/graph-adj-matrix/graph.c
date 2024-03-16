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
    return;
}

void print_graph(graph* g) {
    printf("\nYour Graph:\n\n");

    for (int i = 0; i < g->numnodes; i++)
    {
        printf("\t%d ", i);
    }
    
    printf("\n\n");

    for (int i = 0; i < g->numnodes; i++)
    {
        printf("%d", i);
        for (int j = 0; j < g->numnodes; j++)
        {
            if (g->edges[i][j])
            {
                printf("\t1 ");
            }
            else
            {
                printf("\t0 ");
            }
            
            
        }
        printf("\n");
    }
    
    printf("\n");
}
void add_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    if (has_edge(g, from_node, to_node))
    {
        return;
    }
    
    g->edges[from_node][to_node] = true;
    return;
}

bool has_edge(graph* g, unsigned int from_node, unsigned int to_node) {
    assert(g != NULL);
    assert(from_node < g->numnodes);
    assert(to_node < g->numnodes);

    return g->edges[from_node][to_node];
}