package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Test1(t *testing.T) {

	assert.Equal(t, math.MaxInt32, longestZigZag("91283472332"))
}

func longestZigZag(root *TreeNode) int {
	_, _, total := _longestZigZag(root)
	return total
}

func _longestZigZag(root *TreeNode) (int, int, int) {
	if root == nil {
		return -1, -1, -1
	}
	_, toRight, total1 := _longestZigZag(root.Left)
	toLeft, _, total2 := _longestZigZag(root.Right)

	total := maxInt(total1, total2)
	total = maxInt(total, toLeft+1)
	total = maxInt(total, toRight+1)

	return toRight + 1, toLeft + 1, total
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
