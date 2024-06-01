class Graph:
    def __init__(self, size = int) -> None:
        self.size = size
        self.edges = [[0 for column in range(self.size)] for row in range(self.size)]
    
    def add_edges(self, vertex_a, vertex_b, weight) -> None:
        if self.edges[vertex_a][vertex_b] != 0:
            return
        else:
            self.edges[vertex_a][vertex_b] = weight
            self.edges[vertex_b][vertex_a] = weight
    
    def print_graph(self) -> None:
        print("\nYour Graph:\n")
        for i in range(self.size):
            print(f"\t{i} ", end="")
        print("\n")
        for i in range(self.size):
            print(i, end="")
            for j in range(self.size):
                if self.edges[i][j]:
                    print(f"\t{self.edges[i][j]}", end="")
                else:
                    print("\t-", end="")
            print()