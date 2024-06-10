from graph import Graph
from dijkstra import dijkstra_algorithm

# size = int(input("Enter the total number of vertices: "))

size = 9

graph = Graph(size)

# print("Enter an integer if the vertices are connected, 0 if not connected")
# i = 0
# while i < size:
#     j = 0
#     while j < size:
#         temp = int(input(f"\t{i} -> {j}: "))
#         if temp != 0:
#             graph.connect_vertices(i, j, temp)
#         j += 1
#     i += 1

# graph.print_graph()

# print("\n\n")

graph.adjMatrix = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
           [4, 0, 8, 0, 0, 0, 0, 11, 0],
           [0, 8, 0, 7, 0, 4, 0, 0, 2],
           [0, 0, 7, 0, 9, 14, 0, 0, 0],
           [0, 0, 0, 9, 0, 10, 0, 0, 0],
           [0, 0, 4, 14, 10, 0, 2, 0, 0],
           [0, 0, 0, 0, 0, 2, 0, 1, 6],
           [8, 11, 0, 0, 0, 0, 1, 0, 7],
           [0, 0, 2, 0, 0, 0, 6, 7, 0]
           ]

graph.print_graph()

print("\n\n")

print(dijkstra_algorithm(graph, 0))