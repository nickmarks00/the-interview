"""
Dijkstra's Algorithm
Time complexity (avg): O((V+E)log V) ~= O(E log V) for dense graphs
Time complexity (best): O((V+E)log V) ~= O(E log V) for dense graphs
Time complexity (worst): O(V^2 log V) for dense graphs or suboptimal p.queue operations
Space complexity: O(V)
"""

import heapq

infinity = float("inf")


def make_graph():
    """
    Returns a graph as a dictionary of adjacency lists
    """
    # identical graph as the YouTube video: https://youtu.be/_lHSawdgXpI
    # tuple = (cost, to_node)
    return {
        "A": [(4, "B"), (2, "C")],
        "B": [(3, "C"), (3, "E"), (2, "D")],
        "C": [(1, "B"), (4, "D"), (5, "E")],
        "D": [],
        "E": [(1, "D")],
    }


def dijkstras(g, start_node="A"):
    """
    Runs Dijkstra's algorithm on provided graph using a heap
    """

    shortest_paths = {}
    visited = set()
    heap = []

    for node in g.keys():
        shortest_paths[node] = infinity  # set all starting distances to infinity

    shortest_paths[start_node] = 0

    heapq.heappush(
        heap, (0, start_node)
    )  # keep priority queue of best sub-paths from start node

    while heap:
        (distance, node) = heapq.heappop(
            heap
        )  # node = end node of best sub-path from start node
        visited.add(node)

        for edge in g[node]:
            weight, node_to = edge
            if (node_to not in visited) and (
                distance + weight < shortest_paths[node_to]
            ):
                shortest_paths[node_to] = distance + weight
                heapq.heappush(heap, (shortest_paths[node_to], node_to))

    return shortest_paths


if __name__ == "__main__":

    graph = make_graph()
    print(dijkstras(graph))
