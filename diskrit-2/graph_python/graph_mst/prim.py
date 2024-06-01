import sys
from graph import Graph


def init_prim(target) -> Graph:
    new_tree = Graph(target.size)
    selected = [False for i in range(target.size)]
    edges = 0
    selected[0] = True
    while edges < target.size - 1:
        min_edge_weght = 999999999
        row = 0
        col = 0
        for i in range(target.size):
            if selected[i]:
                for j in range(target.size):
                    if not selected[j] and target.edges[i][j]:
                        if target.edges[i][j] < min_edge_weght:
                            min_edge_weght = target.edges[i][j]
                            col = i
                            row = j
        new_tree.add_edges(col, row, min_edge_weght)
        selected[row] = True
        edges += 1
    return new_tree