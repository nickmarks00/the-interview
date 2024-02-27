/*
	CONTAINER WITH THE MOST WATER
	FROM: LeetCode
	NUMBER: 11
	DIFFICULTY: Medium
	LANGUAGE: Go
	You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoi	nts of the ith line are (i, 0) and (i, height[i]).

	Find two lines that together with the x-axis form a container, such that the container contains the most wat	er.

	Return the maximum amount of water a container can store.

	Notice that you may not slant the container.
*/

package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxArea(height []int) int {
	n := len(height)
	l_ptr := 0
	r_ptr := n - 1

	var maxVolume int

	for l_ptr != r_ptr {
		currVol := (r_ptr - l_ptr) * min(height[l_ptr], height[r_ptr])
		if currVol > maxVolume {
			maxVolume = currVol
		}

		if height[l_ptr] < height[r_ptr] {
			l_ptr += 1
		} else {
			r_ptr -= 1
		}
	}

	return maxVolume
}

func main() {
	// Test cases
	// Test case 1
	// Expected output: 49
	// Explanation: The max volume is obtained by choosing the minimum height of the two lines and multiplying it by the width of the two lines.
	// The width of the two lines is 7 and the minimum height is 7. So, the max volume is 7*7 = 49.
	fmt.Println("Expected: 49 | Actual: ", maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7}))

	// Test case 2
	// Expected output: 1
	// Explanation: The max volume is obtained by choosing the minimum height of the two lines and multiplying it by the width of the two lines.
	// The width of the two lines is 1 and the minimum height is 1. So, the max volume is 1*1 = 1.
	fmt.Println("Expected: 1 | Actual: ", maxArea([]int{1, 1}))

	// Test case 3
	// Expected output: 16
	// Explanation: The max volume is obtained by choosing the minimum height of the two lines and multiplying it by the width of the two lines.
	// The width of the two lines is 4 and the minimum height is 4. So, the max volume is 4*4 = 16.
	fmt.Println("Expected: 16 | Actual: ", maxArea([]int{4, 3, 2, 1, 4}))

	// Test case 4
	// Expected output: 2
	// Explanation: The max volume is obtained by choosing the minimum height of the two lines and multiplying it by the width of the two lines.
	// The width of the two lines is 1 and the minimum height is 2. So, the max volume is 1*2 = 2.
	fmt.Println("Expected: 2 | Actual: ", maxArea([]int{1, 2, 1}))

	// Test case 5
	// Expected output: 24
	// Explanation: The max volume is obtained by choosing the minimum height of the two lines and multiplying it by the width of the two lines.
	// The width of the two lines is 8 and the minimum height is 3. So, the max volume is 8*3 = 24.
	fmt.Println("Expected: 24 | Actual: ", maxArea([]int{1, 3, 2, 5, 25, 24, 5}))
}
