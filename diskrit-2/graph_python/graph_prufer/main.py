from tree import Graph
from prufer import convert_code

size = int(input("Enter the total number of vertices: "))

graph = Graph(size)

print("Enter 1 if the vertices are connected, 0 if not connected")
i = 0
while i < size:
    j = i
    while j < size:
        temp = int(input(f"\t{i} -> {j}: "))
        if temp == 1:
            graph.add_edges(i, j)
        j += 1
    i += 1

graph.print_graph()
# graph.count_edges()

# if graph.is_tree():
#     print("Graph is a tree")
# else:
#     print("Graph is not a tree")

# print(graph.countEdges)

array = [4,1,3,4]

print(array)

graph_prufer = convert_code(array)

graph_prufer.print_graph()