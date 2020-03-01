package src

import (
	"testing"
)

func Test1(t *testing.T) {

	//assert.Equal(t, math.MaxInt32, validateBinaryTreeNodes())
}

func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) bool {
	roots := findRoots(n, leftChild, rightChild)
	if len(roots) != 1 {
		return false
	}

	visited := make([]bool, n)
	valid := visitTree(leftChild, rightChild, roots[0], visited)
	for _, isVisited := range visited {
		if !isVisited {
			valid = false
		}
	}

	return valid
}

func visitTree(leftChild []int, rightChild []int, root int, visited []bool) bool {
	if root == -1 {
		return true
	}
	if visited[root] {
		return false
	}

	visited[root] = true

	return visitTree(leftChild, rightChild, leftChild[root], visited) &&
		visitTree(leftChild, rightChild, rightChild[root], visited)
}

func findRoots(n int, leftChild []int, rightChild []int) []int {
	isChild := make([]bool, n)
	for _, child := range leftChild {
		if child != -1 {
			isChild[child] = true
		}
	}
	for _, child := range rightChild {
		if child != -1 {
			isChild[child] = true
		}
	}

	roots := make([]int, 0, n)
	for i := 0; i < n; i++ {
		if !isChild[i] {
			roots = append(roots, i)
		}
	}

	return roots
}

func absInt(x int) int {
	if x < 0 {
		x *= -1
	}
	return x
}

func maxInt(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func minInt(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func make2DInt(r, c int) [][]int {
	s := make([][]int, r)
	for i := 0; i < r; i++ {
		s[i] = make([]int, c)
	}
	return s
}

func inRange(x, low, high int) bool {
	return x >= low && x < high
}
