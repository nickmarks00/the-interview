"""
Simple implementation of breadth-first search
"""

from collections import deque


def bfs(graph, start_node):
    """
    Runs breadth-first search on a graph from a given starting node
    :param g: a graph in the form of a dictionary with values of edges
    :param start_node: a valid key of g
    """

    visited = set()
    visited.add(start_node)

    queue = deque()
    queue.append(start_node)

    while queue:
        node = queue.popleft()
        print(node, end=" -> ")
        for n in graph[node]:
            if n not in visited:
                visited.add(n)
                queue.append(n)


if __name__ == "__main__":

    g = {
        "A": ["B", "E"],
        "B": ["A", "F"],
        "C": ["D"],
        "D": ["C", "F"],
        "E": ["A", "F"],
        "F": ["B", "D", "E", "G"],
        "G": ["F"],
    }

    print(bfs(g, "A"))  # "A" -> "B" -> "E" -> "F" -> "D" -> "G" -> "C"
