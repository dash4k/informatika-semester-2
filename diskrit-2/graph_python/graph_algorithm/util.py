from graph import Graph
from tabulate import tabulate
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


def add_edge(graph = Graph, size = int, directed=True) -> None:
    print("Enter an integer if the vertices are connected, 0 if not connected")
    status = directed
    i = 0
    while i < size:
        if directed == False:
            j = i
        else:
            j = 0
        while j < size:
            temp = float(input(f"\t{i}    ------->    {j}: "))
            if temp != 0:
                graph.connect_vertices(i, j, temp, directed=status)
            j += 1
        i += 1


def print_coloring(dict = dict, string = string) -> None:
    color_dict = {
        0: "Red",
        1: "Blue",
        2: "Green",
        3: "Yellow",
        4: "Rrange",
        5: "Purple",
        6: "Cyan",
        7: "Magenta",
        8: "Pink",
        9: "Teal",
        10: "Lime"
    }
    print(string)
    for vertex, color in dict.items():
        print(f"\t{vertex} -> {color_dict[color]}")


def print_apsp(list = list, string = string) -> None:
    print(string)
    header = [i for i in range(len(list))]
    # for row in range(len(list)):
    #     for column in range(len(list)):
    #         print(f"\t{row} -> {column} = {list[row][column]}")
    #     print()
    print(tabulate(list, tablefmt="fancy_grid", headers=header, showindex=True))