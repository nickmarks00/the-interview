"""
Insertion sort
Time complexity: O(N^2)
"""


def insertion_sort(lst):
    """
    Sorts lst using insertion sort
    """

    n = len(lst)
    for i in range(1, n):
        current = lst[i]
        j = i - 1
        while j >= 0 and current < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1

        lst[j + 1] = current

    return lst


if __name__ == "__main__":
    a = [99, 0, 5, 20, 123, 0, -1, 72, 21, 22, 13, 8, 7, 67, 29, 1, 2, 4]
    print(insertion_sort(a))
