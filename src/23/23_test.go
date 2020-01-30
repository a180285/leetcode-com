package _23

import (
	"testing"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func Test1(t *testing.T) {

	//[
	//  1->4->5,
	//  1->3->4,
	//  2->6
	//]

}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	if len(lists) > 2 {
		mid := len(lists) / 2
		l1 := mergeKLists(lists[:mid])
		l2 := mergeKLists(lists[mid:])
		return mergeKLists([]*ListNode{l1, l2})
	}

	l1 := lists[0]
	l2 := lists[1]

	head := &ListNode{}
	last := head

	for l1 != nil || l2 != nil {
		if l1 == nil {
			last.Next = l2
			break
		} else if l2 == nil {
			last.Next = l1
			break
		}

		if l1.Val < l2.Val {
			last.Next = l1
			l1 = l1.Next
		} else {
			last.Next = l2
			l2 = l2.Next
		}
		last = last.Next
	}

	return head.Next
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
