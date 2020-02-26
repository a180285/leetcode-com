package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, math.MaxInt32, removeNthFromEnd(nil, 1))
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}

	root := &ListNode{}
	root.Next = reverseList(head)

	tmpNode := root

	for i := 0; i < n-1; i++ {
		tmpNode = tmpNode.Next
	}
	tmpNode.Next = tmpNode.Next.Next

	return reverseList(root.Next)
}

func reverseList(head *ListNode) *ListNode {
	root := &ListNode{}
	for tmpNode := head; tmpNode != nil; {
		nextNode := tmpNode.Next

		tmpNode.Next = root.Next
		root.Next = tmpNode

		tmpNode = nextNode
	}

	return root.Next
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
