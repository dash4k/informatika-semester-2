from graph import Graph

def find_lowest(dict = dict, visited = [], graph = Graph) -> int:
    temp = 999999999
    temp_index = 0
    for i in range(graph.size):
        if temp > dict[i] and not visited[i]:
            temp = dict[i]
            temp_index = i
    return temp_index

def dijkstra_algorithm(graph = Graph, target = int) -> dict:
    short_path = {i: 99999 for i in range(graph.size)}
    visited = [False for i in range(graph.size)]
    short_path[target] = 0
    for i in range(graph.size):
        min_vertex = find_lowest(short_path, visited, graph)
        visited[min_vertex] = True
        for j in range(graph.size):
            if graph.adjMatrix[i][j] > 0 and not visited[j] and short_path[j] > short_path[i] + graph.adjMatrix[i][j]:
                short_path[j] =  short_path[i] + graph.adjMatrix[i][j]
    return short_path
