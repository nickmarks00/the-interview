/*
	DIAMETER OF A BINARY TREE
	FROM: LeetCode
	NUMBER: 543
	DIFFICULTY: Easy
	LANGUAGE: Go
	Given the root of a binary tree, return the length of the diameter of the tree.

	The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path m	ay or may not pass through the root.

	The length of a path between two nodes is represented by the number of edges between them.

*/

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	leftTree := diameterOfBinaryTree(root.Left)
	rightTree := diameterOfBinaryTree(root.Right)
	height := heightOfNode(root.Left) + heightOfNode(root.Right)

	return max(height, max(leftTree, rightTree))
}

func heightOfNode(node *TreeNode) int {
	if node == nil {
		return 0
	}
	return max(heightOfNode(node.Left), heightOfNode(node.Right)) + 1
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func main() {
	// Test cases
	// 1. Empty tree
	// 2. Single node tree
	// 3. Multiple node tree
	// 4. Large tree
	// 5. Large tree with multiple diameters
	fmt.Println("I need some test cases!")
}
