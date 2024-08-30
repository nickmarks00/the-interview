"""
Merge sort
"""


def merge_sort(lst):
    """
    Runs the merge sort routine
    """
    length = len(lst)

    if length == 1:
        return lst

    mid = length // 2

    left = merge_sort(lst[:mid])
    right = merge_sort(lst[mid:])

    return merge(left, right)


def merge(left, right):
    """
    Handles merging of sorted arrays
    """
    output = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            output.append(left[i])
            i += 1
        else:
            output.append(right[j])
            j += 1

    output.extend(left[i:])
    output.extend(right[j:])

    return output


if __name__ == "__main__":
    unsorted = [99, 0, 5, 20, 123, 0, -1, 72, 21, 22, 13, 8, 7, 67, 29, 1, 2, 4]
    sorted_list = merge_sort(unsorted)
    print(sorted_list)

    unsorted = [3, 9, 2, 1]
    sorted_list = merge_sort(unsorted)
    print(sorted_list)
