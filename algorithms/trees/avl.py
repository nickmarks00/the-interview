"""
Implements a self-balancing AVL binary search tree
"""

from collections import deque


class Node:
    """
    Node class for binary search tree
    """

    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


class AVLTree:
    """
    AVL Tree
    """

    def __init__(self):
        self.root = None

    def get_height(self, node):
        """
        Returns the height of the node, with leaves at height 1
        """
        return 0 if not node else node.height

    def get_balance_factor(self, node):
        """
        Returns balance factor of left:right subtree rooted at node
        """
        return (
            0
            if not node
            else (self.get_height(node.left) - self.get_height(node.right))
        )

    def get_min_node(self, node):
        """
        Returns the minimum node in the subtree rooted at node
        """
        return node if not node or not node.left else self.get_min_node(node.left)

    # O(logn)
    def search(self, key):
        """
        Searches for node with key in the tree
        """
        x = self.root
        while x is not None and key != x.key:
            if key < x.key:
                x = x.left
            else:
                x = x.right
        return x

    def insert(self, root, key):
        """
        Inserts a node with key from the root in O(log N)
        """
        if not root:
            return Node(key)

        if key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # Update the balance factor and balance the tree
        bf = self.get_balance_factor(root)

        if bf > 1 and key < root.left.key:
            return self.right_rotate(root)

        if bf < -1 and key > root.right.key:
            return self.left_rotate(root)

        if bf > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        if bf < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def delete(self, root, key):
        """
        Deletes a node with key in O(log N)
        """
        if not root:
            return root

        if key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            if not root.left:
                temp = root.right
                root = None
                return temp

            if not root.right:
                temp = root.left
                root = None
                return temp
            # find inorder successor
            temp = self.get_min_node(root.right)
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))

        # Update the balance factor and balance the tree
        bf = self.get_balance_factor(root)

        if bf > 1 and self.get_balance_factor(root.left) >= 0:
            return self.right_rotate(root)

        if bf < -1 and self.get_balance_factor(root.right) <= 0:
            return self.left_rotate(root)

        if bf > 1 and self.get_balance_factor(root.left) < 0:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        if bf < -1 and self.get_balance_factor(root.right) > 0:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root

    def left_rotate(self, node):
        """
        Performs left rotation in O(1)
        """
        B = node.right
        Y = B.left

        B.left = node
        node.right = Y

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        B.height = 1 + max(self.get_height(B.left), self.get_height(B.right))

        return B

    def right_rotate(self, node):
        """
        Performs right rotation in O(1)
        """
        A = node.left
        Y = A.right

        A.right = node
        node.left = Y

        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))
        A.height = 1 + max(self.get_height(A.left), self.get_height(A.right))

        return A

    def print_tree(self):
        """
        Utility for printing tree using level-order
        """
        if self.root:
            queue = deque()
            queue.append(self.root)

            level_order = ""
            level_order_with_details = ""

            while queue:
                node = queue.popleft()
                level_order += f"{node.key} "
                level_order_with_details += (
                    f"{node.key}: ".ljust(5)
                    + f"h = {self.get_height(node)}, bf = {self.get_balance_factor(node)}\n"
                )

                # add children to queue
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)

            print("\nLevel-order traversal:")
            print(level_order)
            print(
                f"\nLevel-order traversal and height/balance factors: {level_order_with_details}"
            )
        else:
            print("\nAVL tree is empty!")


def print_search_result(result):
    """
    Returns result of search result
    """
    return result.key if result else "not found"


if __name__ == "__main__":
    avl = AVLTree()
    keys = [50, 25, 75, 15, 35, 60, 120, 10, 68, 90, 125, 83, 100]

    for key in keys:
        avl.root = avl.insert(avl.root, key)

    avl.print_tree()

    result = avl.search(125)
    print(f"Search for 125: {print_search_result(result)}")

    result = avl.search(1)
    print(f"Search for 1: {print_search_result(result)}")

    avl.root = avl.delete(avl.root, 120)
    print("\nAfter deleting 120:")
    avl.print_tree()

    avl.root = avl.delete(avl.root, 10)
    print("After deleting 10:")
    avl.print_tree()
