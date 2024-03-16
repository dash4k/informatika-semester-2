#include <stdio.h>
#include "graph.h"

int main(void){
    system("cls");
    int num, count = 0, temp;

    printf("Number of verticies: ");
    scanf("%d", &num);

    graph_t *graph = create_graph(num);

    int *reach = calloc(num, sizeof(int));

    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j < num; j++)
    //     {
    //         add_edges(graph, i, j);
    //     }
        
    // }
    
    printf("Enter 1 if vertex are connected, if not connected enter 0\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("\t%d -> %d: ", i, j);
            scanf("%d", &temp);
            if (temp)
                add_edges(graph, i, j);
        }
        
    }


    print_graph(graph);

    check_connectivity(graph, 0, reach);

    for (int i = 0; i < num; i++)
    {
        if (reach[i])
        {
            count++;
        }
        
    }

    if (count == num)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
}