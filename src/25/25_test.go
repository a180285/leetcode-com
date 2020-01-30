package _25

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	list := makeList([]int{1, 2, 3, 4, 5})
	assert.Equal(t, makeList([]int{2, 1, 4, 3, 5}), reverseKGroup(list, 2))
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	root := &ListNode{}
	last := root
	for head != nil {
		firstList := head
		end := head
		i := 0
		for ; i < k; i++ {
			if head == nil {
				break
			}
			end = head
			head = head.Next
		}
		if i == k {
			end.Next = nil
			firstList = reverseList(firstList)
		}
		last.Next = firstList
		for last.Next != nil {
			last = last.Next
		}
	}
	return root.Next
}

func reverseList(head *ListNode) *ListNode {
	root := &ListNode{}
	for head != nil {
		now := head
		head = head.Next

		now.Next = root.Next
		root.Next = now
	}

	return root.Next
}

func makeList(list []int) *ListNode {
	root := &ListNode{}
	last := root
	for _, i := range list {
		last.Next = &ListNode{i, nil}
		last = last.Next
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
