from graph import Graph
from dijkstra import dijkstra_algorithm
from bellmanFord import bellman_ford
from welshPowell import welsh_powell
from util import clear, ask_int, print_sp, add_edge, print_coloring


flag_1 = flag_2 = True
while flag_1:
    clear()
    print("\t\tMAIN MENU\n")
    print("\t1. Graph Shortest Path")
    print("\t2. Graph Coloring")
    print("\t3. Exit\n")
    choice_main_menu = ask_int("\n\tChoice: ")
    if choice_main_menu == 1:
        clear()
        print("\t\tGraph Shortest Path\n")
        size = ask_int("Enter the total number of vertices: ")
        graph = Graph(size)
        add_edge(graph, size)
        while flag_2:
            clear()
            print("\t\tGraph Shortest Path\n")
            print("\t1. Dijkstra Algorithm")
            print("\t2. Bellman-Ford Algorithm")
            print("\t3. Main Menu\n")
            choice_menu = ask_int("\n\tChoice: ")
            if choice_menu == 1:
                clear()
                print("\t\tGraph Shortest Path\n")
                graph.print_graph()
                target = ask_int("\nInsert the starting point of the Dijkstra algorithm: ")
                if target >= size:
                    input("Incorrect shortest path source.\nPress enter to continue...")
                    continue
                print_sp(dijkstra_algorithm(graph, target), f"\nThe shortest path of each vertex to {target} is:\n")
                input("\n\nPress enter to continue...")
                continue
            if choice_menu == 2:
                clear()
                print("\t\tGraph Shortest Path\n")
                graph.print_graph()
                target = ask_int("\nInsert the starting point of the Bellman-Ford algorithm: ")
                if target >= size:
                    input("Incorrect shortest path source.\nPress enter to continue...")
                    continue
                print_sp(bellman_ford(graph, target), f"\nThe shortest path of each vertex to {target} is:\n")
                input("\n\nPress enter to continue...")
                continue
            if choice_menu == 3:
                flag_2 = False
                continue
            else:
                continue
    if choice_main_menu == 2:
        clear()
        print("\t\tGraph Coloring\n")
        size = ask_int("Enter the total number of vertices: ")
        graph = Graph(size)
        add_edge(graph, size)
        clear()
        print("\t\tGraph Coloring\n")
        graph.print_graph()
        print_coloring(welsh_powell(graph), f"\nThe corresponding color to each vertex of this graph is:\n")
        input("\n\nPress enter to continue...")
        continue
    if choice_main_menu == 3:
        flag_1 = False
        clear()
        continue
    else:
        continue