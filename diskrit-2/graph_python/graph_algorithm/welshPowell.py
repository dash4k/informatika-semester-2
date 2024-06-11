from graph import Graph

def sorted_count_edges(graph = Graph) -> dict:
    graph_edges = {i: 0 for i in range(graph.size)}
    for i in range(graph.size):
        for j in range(graph.size):
            if graph.adjMatrix[i][j] != 0:
                graph_edges[i] += 1
    sorted_graph_edges = dict(sorted(graph_edges.items(), key=lambda item: item[1], reverse=True))
    return sorted_graph_edges

def welsh_powell(graph = Graph) -> dict:
    graph_edges = sorted_count_edges(graph)
    color = {i: -1 for i in range(graph.size)}
    current_color = 0 
    for vertex in graph_edges:
        if color[vertex] == -1:
            color[vertex] = current_color
            for column in range(graph.size):
                if graph.adjMatrix[vertex][column] == 0 and color[column] == -1:
                    color[column] = current_color
            current_color += 1
    return color