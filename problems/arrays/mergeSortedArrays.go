/*
MERGE SORTED ARRAYS
FROM: LeetCode
NUMBER: 88
DIFFICULTY: Easy
LANGUAGE: Go
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

package main

import "fmt"

func merge(nums1 []int, m int, nums2 []int, n int) {
	i := m - 1
	j := n - 1
	ptr := m + n - 1

	for i >= 0 && j >= 0 {
		if nums1[i] >= nums2[j] {
			nums1[ptr] = nums1[i]
			i--
		} else {
			nums1[ptr] = nums2[j]
			j--
		}
		ptr--
	}

	for j >= 0 {
		nums1[ptr] = nums2[j]
		j--
		ptr--
	}
}

func main() {
	inputs1 := [][]int{{1, 2, 3, 0, 0, 0}, {1}, {0}, {4, 5, 6, 0, 0, 0}, {4, 0, 0, 0, 0, 0}}
	in1 := []int{3, 1, 0, 3, 1}
	in2 := []int{3, 0, 1, 3, 5}
	inputs2 := [][]int{{2, 5, 6}, {}, {1}, {1, 2, 3}, {1, 2, 3, 5, 6}}

	for i := 0; i < len(inputs1); i++ {
		merge(inputs1[i], in1[i], inputs2[i], in2[i])
		fmt.Printf("Merged array: %v\n", inputs1[i])
	}
}
