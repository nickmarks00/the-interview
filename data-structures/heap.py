"""
Heap data structure

Time complexities (avg.):
- Insertion = O(log N)
- Deletion = O(log N)
- Searching = O(N)
- Creation via heapify = O(N)
"""


class Heap:
    """
    Class for building and maintaining a MAX heap in form of an array
    """

    def __init__(self, lst):
        self.heap = lst
        self.size = len(lst)

        self.build_max_heap()

    def left(self, i):
        """
        Returns the left child of the node at index i
        Note that this assumes root starts at index 1
        """
        return 2 * i

    def right(self, i):
        """
        Returns the right child of the node at index i
        Note that this assumes root starts at index 1
        """
        return 2 * i + 1

    def parent(self, i):
        """
        Returns the parent of the node at index i
        """
        return i // 2

    def build_max_heap(self):
        """
        Constructs max heap from the lst passed to initialisation
        """
        for i in range(self.size // 2, 0, -1):
            self.max_heapify(i)

    def max_heapify(self, i):
        """
        Maintains the heap invariant in the sub-heap from self.heap[i...N-1]
        """
        l = self.left(i)
        r = self.right(i)
        largest = i

        if l < self.size and self.heap[l] > self.heap[largest]:
            largest = l

        if r < self.size and self.heap[r] > self.heap[largest]:
            largest = r

        if largest != i:
            self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
            self.max_heapify(largest)


if __name__ == "__main__":

    # root is at index 1
    # it can be at index zero but see here:
    # https://www.quora.com/Why-do-indexes-for-heaps-start-at-1
    # and: https://stackoverflow.com/questions/22900388/
    # why-in-a-heap-implemented-by-array-the-index-0-is-left-unused

    a = [None, 0, 5, 20, 6, 12, 65, 1, 4, 9, 3, 89, 22, 25, 28, 10]

    heap = Heap(a)

    # print heap starting with the root at index 1
    print(f"Heap: {a[1:]}")
