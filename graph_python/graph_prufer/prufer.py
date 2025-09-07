from tree import Graph


def convert_code(pruffer_array = []) -> Graph:
    len_array = len(pruffer_array)
    len_graph = len_array + 2
    array = [i for i in range(len_graph)]
    temp_graph = Graph(len_graph)
    for _ in range(len_array):
        x = pruffer_array.pop(0)
        y = min(array)
        while y in pruffer_array:
            y = min(array)
        temp_graph.add_edges(x, y)
        array.remove(y)
    temp_graph.add_edges(array[0], array[1])
    return temp_graph