"""
Prim's algorithm for minimum-spanning trees
"""

import heapq


def make_graph():
    """
    Creates and returns a suitable graph for MST algorithms
    """
    # identical graph as the YouTube video: https://youtu.be/cplfcGZmX7I
    # tuple = (cost, n2, n1)
    return {
        "A": [(3, "D", "A"), (3, "C", "A"), (2, "B", "A")],
        "B": [(2, "A", "B"), (4, "C", "B"), (3, "E", "B")],
        "C": [
            (3, "A", "C"),
            (5, "D", "C"),
            (6, "F", "C"),
            (1, "E", "C"),
            (4, "B", "C"),
        ],
        "D": [(3, "A", "D"), (5, "C", "D"), (7, "F", "D")],
        "E": [(8, "F", "E"), (1, "C", "E"), (3, "B", "E")],
        "F": [(9, "G", "F"), (8, "E", "F"), (6, "C", "F"), (7, "D", "F")],
        "G": [(9, "F", "G")],
    }


def prims(g, start="A"):
    """
    Computes and returns a MST for a supplied graph g built from start
    """
    unvisited = set(g.keys())
    visited = set()
    total_cost = 0
    mst = []

    unvisited.remove(start)
    visited.add(start)

    heap = g[start]
    heapq.heapify(heap)

    while unvisited:
        (cost, n2, n1) = heapq.heappop(heap)
        new_node = None

        if n1 in unvisited and n2 in visited:
            new_node = n1
            mst.append((n2, n1, cost))
        elif n2 in unvisited and n1 in visited:
            new_node = n2
            mst.append((n1, n2, cost))

        if new_node is not None:
            unvisited.remove(new_node)
            visited.add(new_node)
            total_cost += cost

            for edge in g[new_node]:
                heapq.heappush(heap, edge)

    return total_cost, mst


if __name__ == "__main__":
    graph = make_graph()
    sum_cost, tree = prims(graph)
    print(f"Total cost: {sum_cost}\n Tree: {tree}")
