from time import sleep
from tabulate import tabulate


class Graph:
    def __init__(self, size = int) -> None:
        self.size = size
        self.adjMatrix = [[0 for column in range(self.size)] for row in range(self.size)]

    def connect_vertices(self, vertex_a = int, vertex_b = int, weight = int) -> None:
        if self.adjMatrix[vertex_a][vertex_b] != 0:
            return
        else:
            self.adjMatrix[vertex_a][vertex_b] = weight
            self.adjMatrix[vertex_b][vertex_a] = weight
            return
    
    def print_graph(self) -> None:
        header = [i for i in range(self.size)]
        print("\nYour Graph:\n")
        # for i in range(self.size):
        #     print(f"\t{i} ", end="")
        # print("\n")
        # for column in range(self.size):
        #     print(column, end="")
        #     for row in range(self.size):
        #         if self.adjMatrix[column][row]:
        #             print(f"\t{self.adjMatrix[column][row]}", end="")
        #         else:
        #             print("\t-", end="")
        #     print()
        print(tabulate(self.adjMatrix, tablefmt="fancy_grid", headers=header, showindex=True))
