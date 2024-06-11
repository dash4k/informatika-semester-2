from graph import Graph
import os
import string

def clear() -> None:
    if os.name == 'nt':
        os.system('cls')
    else:
        os.system('clear')

def ask_int(string = string) -> int:
    while True:
        try:
            choice = int(input(string))
            return choice
        except ValueError:
            continue

def print_sp(dict = dict, string = string) -> None:
    print(string)
    for vertex, distance in dict.items():
        print(f"\t{vertex} -> {distance}")

def add_edge(graph = Graph, size = int, status="undirected") -> None:
    print("Enter an integer if the vertices are connected, 0 if not connected")
    i = 0
    while i < size:
        if status == "undirected":
            j = i
        else:
            j = 0
        while j < size:
            temp = int(input(f"\t{i} -> {j}: "))
            if temp != 0:
                graph.connect_vertices(i, j, temp)
            j += 1
        i += 1