package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Test1(t *testing.T) {

	assert.Equal(t, math.MaxInt32, isSubPath(nil, nil))
}

func isSubPath(head *ListNode, root *TreeNode) bool {
	return _isSubPath(head, root, false)
}

func _isSubPath(head *ListNode, root *TreeNode, isStarted bool) bool {
	if head == nil {
		return true
	}
	if root == nil {
		return false
	}

	if head.Val == root.Val {
		if _isSubPath(head.Next, root.Left, true) ||
			_isSubPath(head.Next, root.Right, true) {
			return true
		}
	}

	if isStarted {
		return false
	}

	return _isSubPath(head, root.Left, false) ||
		_isSubPath(head, root.Right, false)
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
