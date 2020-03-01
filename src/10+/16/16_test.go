package src

import (
	"github.com/stretchr/testify/assert"
	"math"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 2, threeSumClosest([]int{-1, 2, 1, -4}, 1))
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	minDiff := math.MaxInt32
	result := 0

	for i := 0; i < len(nums); i++ {
		iv := nums[i]
		for j := i + 1; j < len(nums); j++ {
			jv := nums[j]
			find := target - iv - jv
			searchNums := nums[j+1:]
			idx := sort.SearchInts(searchNums, find)
			if idx < len(searchNums) {
				sum := iv + jv + searchNums[idx]
				minDiff, result = checkDiff(minDiff, result, target, sum)
			}
			if idx > 0 {
				idx--
				sum := iv + jv + searchNums[idx]
				minDiff, result = checkDiff(minDiff, result, target, sum)
			}
		}
	}

	return result
}

func checkDiff(minDiff, result, target, sum int) (int, int) {
	diff := absInt(target - sum)
	if minDiff > diff {
		return diff, sum
	}
	return minDiff, result
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
