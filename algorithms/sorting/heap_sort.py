"""
Heap sort implementation
"""

from typing import List


def heapify(arr: List[int], n: int, i: int):
    """
    Constructs a heap recursively from elements i to n
    """
    largest = i  # inspecting subtree rooted at i
    l = 2 * i + 1  # finds location of left child
    r = 2 * i + 2  # finds location of right child

    # check for violations of heap condition on left or right subtree
    if l < n and arr[largest] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        heapify(arr, n, largest)


def heap_sort(arr: List[int]):
    """
    Runs the heap sort routine
    """

    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):  # construct the max heap
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):  # extract max elements one by one
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    return arr


if __name__ == "__main__":
    lst = [4, 10, 3, 5, 1]
    print(heap_sort(lst))
