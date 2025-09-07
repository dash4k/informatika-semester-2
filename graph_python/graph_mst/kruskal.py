from graph import Graph


def count_edges(target = Graph) -> int:
    edges = 0
    for i in range(target.size):
        for j in range(target.size):
            if target.edges[i][j] != 0:
                edges += 1
    return edges


def sort_edge_array(edge_array = []) -> None:
    edge_array.sort(key=lambda x: (x[1]))


def merge_union(union_array = [], len = int, edge_1 = int, edge_2 = int) -> None:
    for i in range(len):
        if union_array[i] == edge_2:
            union_array[i] = edge_1


def init_kruskal(target = Graph) -> Graph:
    new_tree = Graph(target.size)
    union_array = [i for i in range(target.size)]
    temp_edge_array = [[0 for column in range(3)] for row in range(target.size)]
    temp_edge_count = 0
    for i in range(target.size):
        for j in range(i+1, target.size):
            if target.edges[i][j] != 0:
                temp_edge_array[temp_edge_count][0] = i
                temp_edge_array[temp_edge_count][1] = j
                temp_edge_array[temp_edge_count][2] = target.edges[i][j]
                temp_edge_count += 1
    real_edge_array = [[0 for column in range(3)] for row in range(target.size)]
    real_edge_count = 0
    sort_edge_array(temp_edge_array)
    for i in range(temp_edge_count):
        vertex_1 = union_array[temp_edge_array[i][0]]
        vertex_2 = union_array[temp_edge_array[i][1]]
        if vertex_1 != vertex_2:
            real_edge_array[real_edge_count] = temp_edge_array[i]
            real_edge_count += 1
            merge_union(union_array, target.size, vertex_1, vertex_2)
    for i in range(real_edge_count):
        new_tree.add_edges(real_edge_array[i][0], real_edge_array[i][1], real_edge_array[i][2])
    return new_tree