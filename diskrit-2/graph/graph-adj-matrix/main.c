#include "graph.h"
#include <stdio.h>

int main(void) {
    system("cls");
    int num, temp;
    printf("Number of vertex: ");
    scanf("%d", &num);

    graph *g1 = create_graph(num);
    

    // add_edge(g1, 0, 1);
    // add_edge(g1, 0, 2);
    // add_edge(g1, 0, 0);
    // add_edge(g1, 1, 2);
    // add_edge(g1, 1, 3);
    // add_edge(g1, 3, 4);
    // add_edge(g1, 4, 1);
    // add_edge(g1, 4, 0);

    printf("Enter 1 if vertex are connected, if not connected enter 0\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("\t%d -> %d: ", i, j);
            scanf("%d", &temp);
            if (temp)
                add_edge(g1, i, j);
        }
        
    }
    

    print_graph(g1);

    destroy_graph(g1);
}