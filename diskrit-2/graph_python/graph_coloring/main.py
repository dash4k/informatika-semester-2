from graph import Graph

size = int(input("Enter the total number of vertices: "))

graph = Graph(size)

print("Enter 1 if the vertices are connected, 0 if not connected")
for i in range(size):
    for j in range(size):
        temp = int(input(f"\t{i} -> {j}: "))
        if temp == 1:
            graph.add_edge(i, j)

graph.print_list()

graph.coloring()

graph.is_connected()

graph.is_directed()