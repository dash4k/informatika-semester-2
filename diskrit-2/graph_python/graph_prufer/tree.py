class Graph:
    def __init__(self, size=int) -> None:
        self.size = size
        self.edges = [[False for column in range(self.size)] for row in range(self.size)]
        self.countEdges = [[0 for column in range(2)] for row in range(self.size)]

    def add_edges(self, vertex_a, vertex_b) -> None:
        if self.edges[vertex_a][vertex_b]:
            return
        else:
            self.edges[vertex_a][vertex_b] = True
            self.edges[vertex_b][vertex_a] = True

    def print_graph(self) -> None:
        print("\nYour Graph:\n")
        for i in range(self.size):
            print(f"\t{i} ", end="")
        print("\n")
        for i in range(self.size):
            print(i, end="")
            for j in range(self.size):
                if self.edges[i][j]:
                    print("\tx", end="")
                else:
                    print("\t-", end="")
            print()

    def is_cycle(self, random_start=int, parent=int, reach=[]) -> bool:
        reach[random_start] = True
        for i in range(self.size):
            if self.edges[random_start][i]:
                if not reach[i]:
                    if self.is_cycle(i, random_start, reach):
                        return True
                elif i != parent:
                    return True
        return False

    def is_tree(self) -> bool:
        reach = [False for row in range(self.size)]
        if self.is_cycle(0, -1, reach):
            return False
        return True
    
    def count_edges(self) -> None:
        for i in range(self.size):
            self.countEdges[i][0] = i
            self.countEdges[i][1] = 0
            for j in range(self.size):
                if self.edges[i][j]:
                    self.countEdges[i][1] += 1
    
    def sort_edges(self) -> None:
        self.countEdges.sort(key=lambda x: (x[1], x[0]))
    
    def prufer_codes(self):
        # prufer_array = [None]*(self.size - 2)
        prufer_array = [None for row in range(self.size - 2)]
        self.count_edges()
        for i in range(self.size - 2):
            self.sort_edges()
            next = -1
            for j in range(self.size):
                if self.edges[self.countEdges[i][0]][j]:
                    next = j
                    break
            if next != -1:
                prufer_array[i] = next
                self.edges[self.countEdges[i][0]][next] = self.edges[next][self.countEdges[i][0]] = False
                self.countEdges[i][1] -= 1
                for j in range(self.size):
                    if self.countEdges[j][0] == next:
                        self.countEdges[j][1] -= 1
        return prufer_array