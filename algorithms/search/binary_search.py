"""
Binary search
Time complexity: O(log N)
"""


def binary_search(lst, target):
    """
    Runs binary search for target in lst
    """

    l = 0
    r = len(lst) - 1

    while l <= r:
        mid = (l + r) // 2
        if lst[mid] < target:
            l = mid + 1
        elif lst[mid] > target:
            r = mid - 1
        else:
            return mid

    return -1


if __name__ == "__main__":
    array = [1, 4, 5, 7, 9, 12, 15, 18, 19, 22, 25, 29, 40, 50]
    print(f"Index of 12: {binary_search(array, 12)}")
    print(f"Index of 1: {binary_search(array, 1)}")
    print(f"Index of 9: {binary_search(array, 9)}")
    print(f"Index of 22: {binary_search(array, 22)}")
    print(f"Index of 50: {binary_search(array, 50)}")
    print(f"Index of -1: {binary_search(array, -1)}")
