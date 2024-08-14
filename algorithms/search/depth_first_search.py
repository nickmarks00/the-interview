"""
Simple implementation of breadth-first search
"""


def dfs(graph, start_node):
    """
    Runs depth-first search on a graph from a given starting node
    :param g: a graph in the form of a dictionary with values of edges
    :param start_node: a valid key of g
    """

    visited = set()
    stack = []

    visited.add(start_node)
    stack.append(start_node)

    while stack:
        node = stack.pop()
        print(node, end=" -> ")

        for n in reversed(graph[node]):
            if n not in visited:
                visited.add(n)
                stack.append(n)


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

    dfs(g, "A")  # "A" -> "B" -> "F" -> "D" -> "C" -> "E" -> "G"
