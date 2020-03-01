package src

import (
	"github.com/stretchr/testify/assert"
	"sort"
	"testing"
)

func Test1(t *testing.T) {

	assert.Equal(t, [][]int{{-1, -1, 2}, {-1, 0, 1}}, threeSum([]int{-1, 0, 1, 2, -1, -4}))
	assert.Equal(t, [][]int{{0, 0, 0}}, threeSum([]int{0, 0, 0, 0}))
}

func threeSum(nums []int) [][]int {
	results := [][]int{}
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			break
		}

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums); j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			sum := nums[i] + nums[j]
			if sum > 0 {
				break
			}
			newsList := nums[j+1:]
			idx := sort.SearchInts(newsList, -sum)
			if idx < len(newsList) && newsList[idx] == -sum {
				results = append(results, []int{nums[i], nums[j], newsList[idx]})
			}
		}
	}

	return results
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
