/*
* MINIMUM LENGTH OF STRING AFTER DELETING SIMILAR ENDS
* FROM: LeetCode
* NUMBER: 1750
* LEVEL: Medium
* LANGUAGE: Go
* Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:

1. Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
2. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
3. The prefix and the suffix should not intersect at any index.
4. The characters from the prefix and suffix must be the same.
5. Delete both the prefix and the suffix.

Return the minimum length of s after performing the above operation any number of times (possibly zero times).
*/

package main

import "fmt"

func minimumLength(s string) int {
	n := len(s)
	i := 0
	j := n - 1

	for i < j && s[i] == s[j] {
		for i < j && s[i] == s[i+1] {
			i++
		}

		for j > i && s[j] == s[j-1] {
			j--
		}
		i++
		j--
	}

	return max(j-i+1, 0)
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	s := "ca"
	fmt.Println("Expected: 2, Got: ", minimumLength(s))
	s = "cabaabac"
	fmt.Println("Expected: 0, Got: ", minimumLength(s))
	s = "aabccabba"
	fmt.Println("Expected: 3, Got: ", minimumLength(s))
}
