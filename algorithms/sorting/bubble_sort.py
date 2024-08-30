"""
Bubble sort with optimisation for early break
"""


def bubble_sort(lst):
    """
    Bubble sort
    - Optimised to detect no swapping -> break early
    - Optimised to not repeat final iteration (left subarray lst[0] is trivially sorted)
    """
    n = len(lst)
    for j in range(n - 1, 0, -1):
        swapped = False
        for i in range(j):
            if lst[i] > lst[i + 1]:
                lst[i], lst[i + 1] = lst[i + 1], lst[i]
                swapped = True
        if not swapped:
            break
    return lst


if __name__ == "__main__":
    array = [2, 3, 1, 4, 5, -1, 0]
    print(bubble_sort(array))
