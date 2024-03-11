/*
CUSTOM SORT STRING
NUMEBR: 791
FROM: LeetCode
DIFFICULTY: Medium
LANGUAGE: Go

You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/
package main

import (
	"fmt"
	"strings"
)

func customSortString(order string, s string) string {
	var freq [26]int

	for _, c := range s {
		freq[c-'a']++
	}

	ans := strings.Builder{}
	for _, c := range order {
		for freq[c-'a'] > 0 {
			freq[c-'a']--
			ans.WriteString(string(c))
		}
	}

	for c := 'a'; c <= 'z'; c++ {
		for freq[c-'a'] > 0 {
			freq[c-'a']--
			ans.WriteString(string(c))
		}
	}
	return ans.String()
}

func main() {
	order := "cba"
	s := "abcd"
	expected := "cbad"

	fmt.Printf("Expected %s. Got %s\n", expected, customSortString(order, s))
}
