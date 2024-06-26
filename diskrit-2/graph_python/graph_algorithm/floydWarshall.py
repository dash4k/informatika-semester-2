from graph import Graph


def copy(graph = Graph) -> list:
    list_copy = [[0 for row in range(graph.size)] for column in range(graph.size)]
    for row in range(graph.size):
        for column in range(graph.size):
            list_copy[row][column] = graph.adjMatrix[row][column]
    return list_copy


def floyd_warshall(graph = Graph) -> list:
    apsp = copy(graph)
    for k in range(graph.size):
        for i in range(graph.size):
            for j in range(graph.size):
                apsp[i][j] = min(apsp[i][j], apsp[i][k] + apsp[k][j])
                if i == j and apsp[i][j] < 0:
                    print("\nThe graph contains a negative weight cycle!\n")
                    return
    return apsp