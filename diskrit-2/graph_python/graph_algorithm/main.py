from graph import Graph
from dijkstra import dijkstra_algorithm

size = int(input("Enter the total number of vertices: "))

graph = Graph(size)

print("Enter an integer if the vertices are connected, 0 if not connected")
i = 0
while i < size:
    j = 0
    while j < size:
        temp = int(input(f"\t{i} -> {j}: "))
        if temp != 0:
            graph.connect_vertices(i, j, temp)
        j += 1
    i += 1

graph.print_graph()

print("\n\n")

print(dijkstra_algorithm(graph, 0))