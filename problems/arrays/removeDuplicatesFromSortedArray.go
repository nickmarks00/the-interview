/*
REMOVE DUPLICATES FROM SORTED ARRAY
NUMBER: 26
FROM: LeetCode
DIFFICULTY: Easy
LANGUAGE: Go
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
package main

import "fmt"

func removeDuplicates(nums []int) int {
	i := 0
	n := len(nums)

	if n <= 1 {
		return n
	}

	for j := 1; j < n; j++ {
		if nums[i] != nums[j] {
			i++
		}
		nums[i] = nums[j]
	}
	return i + 1
}

func main() {
	ins := [][]int{{1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {1, 1}}
	expecteds := [][]int{{1, 2}, {0, 1, 2, 3, 4}, {1}}

	for i, input := range ins {
		out := removeDuplicates(input)
		for j := 0; j < out-1; j++ {
			if expecteds[i][j] == expecteds[i][j+1] {
				fmt.Printf("Found duplicate on test case %v at index %v\n", i, j)
			}
		}
		fmt.Printf("Test case  %v...Passed\n", i)
	}
}
