/*
MAXIMUM SUBARRAY
FROM: LeetCode
NUMBER: 53
DIFFICULTY: Medium
LANGUAGE: Go

Given an integer array nums, find the subarray with the largest sum, and return its sum.

AKA KADANE'S ALGORITHM
*/

package main

import "fmt"

func maxSubArray(nums []int) int {
	maxCurr := nums[0]
	maxGlobal := nums[0]
	for i := 1; i < len(nums); i++ {
		maxCurr = max(maxCurr+nums[i], nums[i])
		maxGlobal = max(maxCurr, maxGlobal)
	}

	return maxGlobal
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	fmt.Println("Expected: 6, Output: ", maxSubArray(nums))

	nums = []int{1}
	fmt.Println("Expected: 1, Output: ", maxSubArray(nums))

	nums = []int{5, 4, -1, 7, 8}
	fmt.Println("Expected: 23, Output: ", maxSubArray(nums))
}
