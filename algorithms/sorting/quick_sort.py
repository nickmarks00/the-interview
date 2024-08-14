"""
Quick sort
"""


def partition(lst, low, high):
    """
    Partitions a subarray from lst[low...high] and returns index of partition
    """

    i = low
    pivot = lst[high]

    for j in range(low, high):
        if lst[j] <= pivot:
            lst[i], lst[j] = lst[j], lst[i]
            i += 1

    lst[i], lst[high] = lst[high], lst[i]

    return i


def quick_sort(lst, low, high):
    """
    Sorts array via quick sort recursively
    """

    if low < high:
        partition_index = partition(lst, low, high)
        quick_sort(lst, low, partition_index - 1)
        quick_sort(lst, partition_index + 1, high)


if __name__ == "__main__":

    a = [99, 0, 5, 20, 123, 0, -1, 72, 21, 22, 13, 8, 7, 67, 29, 1, 2, 4]
    quick_sort(a, 0, len(a) - 1)
    print(a)

    b = [3, 9, 2, 1]
    quick_sort(b, 0, len(b) - 1)
    print(b)
