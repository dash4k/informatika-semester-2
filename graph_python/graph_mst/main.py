from graph import Graph
from prim import init_prim
from kruskal import init_kruskal

size = int(input("Enter the total number of vertices: "))

graph = Graph(size)

print("Enter an integer if the vertices are connected, 0 if not connected")
i = 0
while i < size:
    j = i
    while j < size:
        temp = int(input(f"\t{i} -> {j}: "))
        if temp != 0:
            graph.add_edges(i, j, temp)
        j += 1
    i += 1

graph.print_graph()

print("\n\n")

tree = init_kruskal(graph)

tree.print_graph()