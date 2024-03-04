/*
REMOVE ELEMENT
FROM: LeetCode
NUMBER: 27
DIFFICULTY: Easy
LANGUAGE: Go
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

package main

func removeElement(nums []int, val int) int {
	j := -1
	for i, num := range nums {
		if num != val && j != -1 {
			nums[i], nums[j] = nums[j], nums[i]
			j += 1
		} else if num == val && j == -1 {
			j = i
		}
	}
	if j == -1 {
		return len(nums)
	}
	return j
}
