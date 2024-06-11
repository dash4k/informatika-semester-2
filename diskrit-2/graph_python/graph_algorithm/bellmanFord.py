from graph import Graph

def bellman_ford(graph = Graph, target = int) -> dict:
    short_path = {i: 1e9 for i in range(graph.size)}
    short_path[target] = 0
    for _ in range(graph.size-1):
        for i in range(graph.size):
            for j in range(graph.size):
                if short_path[i] != 1e9 and graph.adjMatrix[i][j] != 0:
                    if short_path[i] + graph.adjMatrix[i][j] < short_path[j]:
                        short_path[j] = short_path[i] + graph.adjMatrix[i][j]
    for i in range(graph.size):
            for j in range(graph.size):
                if short_path[i] != 1e9 and graph.adjMatrix[i][j] != 0:
                    if short_path[i] + graph.adjMatrix[i][j] < short_path[j]:
                        print("The graph contain a negative weight cycle")
                        return
    return short_path