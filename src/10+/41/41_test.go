package src

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, 3, firstMissingPositive([]int{1, 2, 0, -1, 7}))
	assert.Equal(t, 2, firstMissingPositive([]int{3, 4, -1, 1}))
}

func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); i++ {
		num := nums[i]
		if num <= 0 || num > len(nums) {
			continue
		}
		if nums[i] == nums[num-1] {
			continue
		}
		nums[i], nums[num-1] = nums[num-1], nums[i]
		i--
	}
	for i, num := range nums {
		if i+1 != num {
			return i + 1
		}
	}

	return len(nums) + 1
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
