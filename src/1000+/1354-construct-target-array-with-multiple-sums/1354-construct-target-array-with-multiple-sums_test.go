package src

import (
	"container/heap"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {
	assert.Equal(t, false, isPossible([]int{2}))
	assert.Equal(t, true, isPossible([]int{5, 2}))

	assert.Equal(t, false, isPossible([]int{2, 900000002}))
	assert.Equal(t, false, isPossible([]int{1, 1, 1, 2}))
	assert.Equal(t, false, isPossible([]int{1, 1, 1, 3}))
	assert.Equal(t, true, isPossible([]int{9, 3, 5}))
	assert.Equal(t, true, isPossible([]int{8, 5}))
	assert.Equal(t, true, isPossible([]int{1, 1000000000}))
}

type HeapNode struct {
	val, idx int
}

// An IntHeap is a min-heap of ints.
type MyHeap []HeapNode

func (h MyHeap) Len() int           { return len(h) }
func (h MyHeap) Less(i, j int) bool { return h[i].val > h[j].val }
func (h MyHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MyHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(HeapNode))
}

func (h *MyHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func isPossible(target []int) bool {
	maxValueHeap := MyHeap{}
	sum := 0
	for id, val := range target {
		sum += val
		if val != 1 {
			maxValueHeap = append(maxValueHeap, HeapNode{val: val, idx: id})
		}
	}

	heap.Init(&maxValueHeap)

	for maxValueHeap.Len() > 0 {
		maxItem := heap.Pop(&maxValueHeap).(HeapNode)
		oldMax := maxItem.val
		leftSum := sum - oldMax
		if leftSum == 1 {
			return true
		}

		if oldMax <= leftSum || leftSum < 1 {
			return false
		}

		nextVal := oldMax % leftSum
		if nextVal == 0 {
			return false
		}
		if nextVal > 1 {
			heap.Push(&maxValueHeap, HeapNode{val: nextVal, idx: maxItem.idx})
		}

		target[maxItem.idx] = nextVal
		sum = leftSum + nextVal
	}

	return true
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
