package src

import (
	"math"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	//assert.Equal(t, math.MaxInt32, kthSmallest("91283472332"))
}

func kthSmallest(arrays [][]int, k int) int {
	k--
	low, high := math.MinInt32, math.MaxInt32

	for low < high { // make sure f(low) <= k
		mid := (low + high + 1) / 2
		index := findIndex(arrays, mid)
		if index <= k {
			low = mid
		} else {
			high = mid - 1
		}
	}

	return low
}

func findIndex(arrays [][]int, val int) int {
	index := 0

	for i := 0; i < len(arrays); i++ {
		index += sort.SearchInts(arrays[i], val)
	}

	return index
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
