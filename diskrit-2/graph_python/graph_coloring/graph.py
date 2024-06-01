class Node:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None
        

class Graph:
    def __init__(self, num = int) -> None:
        self.size = num
        self.graph = [None] * self.size

    def add_edge(self, vertex_a, vertex_b) -> None:
        node = Node(vertex_b)
        node.next = self.graph[vertex_a]
        self.graph[vertex_a] = node

    def print_list(self) -> None:
        print("\nAdjancecy List: \n")
        for i in range(self.size):
            print(f"Vertex {i}:", end="")
            temp = self.graph[i]
            while temp:
                print(f" -> {temp.data}", end="")
                temp = temp.next
            print(" \n")

    def coloring(self) -> None:
        result = [-1] * self.size
        available = [True] * self.size
        if self.size == 2:
            result[0] = 0
            result[1] = 1
            for i in range(self.size):
                print(f"Vertex {i} --> Color {result[i]}")
        else:
            result[0] = 0
            for v in range(1, self.size):
                temp = self.graph[v]
                while temp:
                    if result[temp.data] != -1:
                        available[result[temp.data]] = False
                    temp = temp.next
                for count in range(self.size):
                    if available[count]:
                        break
                result[v] = count
                temp = self.graph[v]
                while temp:
                    if result[temp.data] != -1:
                        available[result[temp.data]] = True
                    temp = temp.next
            for i in range(self.size):
                print(f"Vertex {i} --> Color {result[i]}")

    def dfs(self, random_start = int, reach = []) -> None:
        reach[random_start] = 1
        temp = self.graph[random_start]
        while temp:
            if reach[temp.data] != 1:
                self.dfs(temp.data, reach)
            temp = temp.next
    
    def is_connected(self) -> None:
        for i in range(self.size):
            count = 0
            reach = [0] * self.size
            self.dfs(i, reach)
            for j in reach:
                if j == 1:
                    count += 1
            if count == self.size:
                print("\nGraph is Connected")
                return
        print("\nGraph is Disconected")
        return
    
    def is_directed(self) -> None:
        reach1 = [0] * self.size
        reach2 = [0] * self.size
        for i in range(self.size):
            self.dfs(i - 1, reach1)
            self.dfs(i, reach2)
            for j in range(self.size):
                if (reach1[j] == 1 and reach2[j] == 0) or (reach1[j] == 0 and reach2[j] == 1):
                    print("\nGraph is Directed")
                    return
        print("\nGraph is Undirected")

    